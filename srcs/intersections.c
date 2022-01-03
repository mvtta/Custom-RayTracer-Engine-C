/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2022/01/03 20:01:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* useful equation cheat sheet:
Standard line eq:
𝑎 𝑥 + 𝑏 𝑦 + 𝑐 = 0
The equation of the line can also be realized as a dot product of two vectors as
Standard eq plane :
 𝑎 𝑥 + 𝑏 𝑦 + 𝑐 𝑧 + 𝑑 = 0
Plane from 2 points:
𝑎 ( 𝑥 − 𝑥 ) + 𝑏 ( 𝑦 − 𝑦 ) + 𝑐 ( 𝑧 − 𝑧 ) = 0
Normal vector on olane given two vects on point:
cross_p

ray_plane intersections:
point in plane: (p−p0)⋅n=0
ray : l0+l∗t=p
two eqs in one : (l0+l∗t−p0)⋅n=0
compute t:
t = =−(l0−p0)⋅n/ l⋅n
- l0 is the origin of the ray
-  l is the ray direction
- p0 point far away in plane
- n normm vec
*/

float ray_sphere(t_ray *r, t_obj *s, t_vec obj_coord)
{

	t_vec dist = v_sub(&r->start, &obj_coord);

	float radius = (s->diameter) / 2;
	float a = dot_p(&r->dir, &r->dir);
	float b = 2.0 * dot_p(&r->dir, &dist);
	float c = dot_p(&dist, &dist) - (radius * radius);
	float discr = b * b - 4 * a * c;
	if (discr >= 0)
		return(discr);
	return (NO_HIT);
}

float ray_plane(t_ray *r, t_obj *p, t_vec obj_coord)
{

	//t_vec norm_dir = normalize(&r->dir);
	//t_vec norm_coord = normalize(&obj_coord);
	t_vec d = v_add(&r->start, &r->dir);
	float len = length(d);
	d = v_scale(len, &d);
	t_vec p1 = normalize(&obj_coord);
	float denom = dot_p(&d, p->obj_norm);
	float point = dot_p(&d, &p1);
	float t = denom / point;
	if(t > 0.001 && t < 200)
	{
/* 		printf("t:%f\n", t);
		printf("denom:%f\n", denom);
		printf("point:%f\n", point); */
		return(t);
	}
	return (NO_HIT);
}

/* 	t_vec plane_norm;
	plane_norm = cross_p(p->obj_coord, );
	t_vec dist = v_mult(&r->dir, &obj_coord);
	float divide = dot_p(&dist, &obj_coord);
	float	d;
	//divide /= 10;
	d = dot_p(&dist, &plane_norm) * divide;
	if(d >= 0 && d < 0.01)
	{
		//printf("\t SIMPLE D : %f\n", d);
		return ((d));
	}
	else
		return(NO_HIT); */

/* var d = Vector3.Dot(planeP, -planeN);
   var t = -(d + rayP.z * planeN.z + rayP.y * planeN.y + rayP.x * planeN.x) / (rayD.z * planeN.z + rayD.y * planeN.y + rayD.x * planeN.x);
   return rayP + t * rayD; */
// return((-b - sqrt(discr) ) / (2.0*a));