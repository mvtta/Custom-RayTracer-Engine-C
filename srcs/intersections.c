/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2021/11/24 10:04:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

bool ray_sphere(t_ray *r, t_obj *s)
{
	
	/* A = d.d, the vector dot product of the direction */

    float radius = s->diameter / 2;
	float a = dot_p(&r->dir, &r->dir);
    printf("a: %f\n", a);
    printf("radius: %f\n", radius);
	
	/* We need a vector representing the distance between the start of 
	 * the ray and the position of the circle.
	 * This is the term (p0 - c) 
	 */
	t_vec dist = v_sub(&r->start, s->obj_coord);
	
	/* 2d.(p0 - c) */  
	float b = 2 * dot_p(&r->dir, &dist);
    printf("b: %f\n", b);
	
	
	/* (p0 - c).(p0 - c) - r^2 */
	float c = dot_p(&dist, &dist) - (radius * radius);
	
    printf("c: %f\n", c);
	/* Solving the discriminant */
	float discr = b * b - 4 * a * c;
    printf("discr: %f\n", discr);
	
	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 */
	if(discr < 0)
		return false;
	else
		return true;
}
 