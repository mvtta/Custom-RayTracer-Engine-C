/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2021/12/14 17:24:25 by mvaldeta         ###   ########.fr       */
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

	float denom;
	t_vec plane_norm;
	plane_norm = normalize(&obj_coord);
	t_vec point_minus_origin = v_sub(&obj_coord, &r->start);
	float divide = dot_p(&r->dir, &plane_norm);
	t_vec dist = v_sub(&r->start, &obj_coord);
	denom = dot_p(p->obj_norm, &obj_coord);
	float a = dot_p(&r->dir, &r->dir);
	float b = dot_p(&r->dir, &dist);
	float c = dot_p(&dist, &dist) - denom;
	float	d;
	//t_vec	plane = obj_coord;
	t_vec	abc;
	abc.x = a;
	abc.y = b;
	abc.z = c;
	float nonsense;

	
	nonsense = dot_p(p->obj_coord, &plane_norm);
	//t_vec	where = v_mult(&abc, &plane);
	d = dot_p(&point_minus_origin, &plane_norm) / divide;
	
	if(d >= 0)
	{
		printf("\t SIMPLE D : %f\n", d);
		return ((d));
	}
	else
		return(NO_HIT);
}


 /* var d = Vector3.Dot(planeP, -planeN);
    var t = -(d + rayP.z * planeN.z + rayP.y * planeN.y + rayP.x * planeN.x) / (rayD.z * planeN.z + rayD.y * planeN.y + rayD.x * planeN.x);
    return rayP + t * rayD; */
//return((-b - sqrt(discr) ) / (2.0*a));