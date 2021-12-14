/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2021/12/13 19:19:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float ray_sphere(t_ray *r, t_obj *s, t_vec obj_coord)
{

	t_vec dist = v_sub(&r->start, &obj_coord);
	
	float scale = 3.5; 
	float radius = (s->diameter * scale) / 2;
	float a = dot_p(&r->dir, &r->dir);
	float b = 2 * dot_p(&r->dir, &dist);
	float c = dot_p(&dist, &dist) - (radius * radius);
	float discr = b * b - 4 * a * c;
	if(discr < 0)
		return(NO_HIT);
	else
		return((-b - sqrt(discr) ) / (2.0*a));
}


float ray_plane(t_ray *r, t_obj *p, t_vec obj_coord)
{

	float	denom;
	float	t = 0;
	t_vec	p0l0;

	denom = dot_p(p->obj_norm, &r->dir);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = v_sub(&obj_coord, &r->start);
		t = dot_p(&p0l0, p->obj_norm) / denom;
	}
	if(t >= 0)
		return (t);
	else
		return(NO_HIT);
}


 /* var d = Vector3.Dot(planeP, -planeN);
    var t = -(d + rayP.z * planeN.z + rayP.y * planeN.y + rayP.x * planeN.x) / (rayD.z * planeN.z + rayD.y * planeN.y + rayD.x * planeN.x);
    return rayP + t * rayD; */
//return((-b - sqrt(discr) ) / (2.0*a));