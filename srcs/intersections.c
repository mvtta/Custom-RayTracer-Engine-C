/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2021/11/24 17:08:56 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

bool ray_sphere(t_ray *r, t_obj *s)
{

	float radius = s->diameter / 2;
	float a = dot_p(&r->dir, &r->dir);
	t_vec dist = v_sub(&r->start, s->obj_coord);
	float b = 2 * dot_p(&r->dir, &dist);
	float c = dot_p(&dist, &dist) - (radius * radius);
	float discr = b * b - 4 * a * c;

	printf("**********INTERSECTION*************");

	printf("a: %f\n", a);
	printf("radius: %f\n", radius);
	printf("b: %f\n", b);
	printf("c: %f\n", c);
	printf("discr: %f\n", discr);
	
	if (discr >= 0)
		return true;
	else
		return false;
}
