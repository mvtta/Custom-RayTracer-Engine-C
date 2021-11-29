/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2021/11/29 16:12:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float ray_sphere(t_ray *r, t_obj *s, t_vec obj_coord)
{

	t_vec dist = v_sub(&r->start, &obj_coord);
	
	float scale = 5; 
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

//return((-b - sqrt(discr) ) / (2.0*a));