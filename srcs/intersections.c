/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2022/01/27 09:58:13 by user             ###   ########.fr       */
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

	t_vec d = v_add(&r->start, &r->dir);
	t_vec dist = v_sub(&obj_coord, &d);

	float radius = (s->diameter) / 2;
	float a = dot_p(&r->dir, &r->dir);
	float b = 2.0 * dot_p(&r->dir, &dist);
	float c = dot_p(&dist, &dist) - (radius * radius);
	float discr = b * b - 4 * a * c;
	if (discr >= 0)
	{
		if (discr == 0)
		{
			float t0 = -0.5 * b / a;
			printf("\tprintf t0: %f\n", t0);
			return (t0);
		}
		float q = MAX(-0.5 * (b + sqrtf(discr)), -0.5 * (b - sqrtf(discr)));
		float t1 = q / 2 * a;
		float t2 = c / q;
		if (t1 > t2)
		{
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		if (t1 < 0)
			t1 = t2;
		if (t1 > 0)
		{
			// printf("\t printf t1: %f\n", t1);
			/* 		printf("\t LEN: %f\n", len); */
			return (t1);
		}
	}
	return (NO_HIT);
}

float ray_cy(t_ray *r, t_obj *p, t_vec obj_coord)
{
	t_vec dist;
	t_vec orig;
	t_vec eye;
	t_vec rot;
	t_vec c_to_rot;
	dist = v_sub(&r->dir, &obj_coord);
	orig = v_sub(&r->start, &obj_coord);
	eye = cross_p(orig, dist);
	rot = cross_p(r->dir, dist);
	c_to_rot = cross_p(orig, *p->obj_norm);
	eye = normalize(&eye);
	rot = normalize(&rot);
	c_to_rot = normalize(&c_to_rot);
	//t_vec rot = cross_p(c_to_o, *p->obj_norm);

	float a = dot_p(&rot, &rot);
	//printf("A:%f\n", a);
	float b = 2.0 * dot_p(&rot, &eye);
	//printf("B:%f\n", b);
	float c = dot_p(&c_to_rot, &c_to_rot) - (3.0 / 2);
	//printf("C:%f\n", c);
	float discr = sqrt((b * b) - (4.0 * a * c));
	//exit(0);
	if (discr >= 0)
	{
		//printf("discr:%f\n", discr);
		float t1 = (-b -sqrtf(discr)) / (2 * a);
		float t2 = (-b +sqrtf(discr)) / (2 * a);
		float t = t1;
		double max = (sqrtf(3) * sqrtf(5));
		t_vec point = v_add(&r->start, &r->dir);
		point = v_scale(t, &point);
		t_vec len = v_sub(&point, p->obj_coord);
		float nlen = length(len);
		//printf("nlen%f\n", nlen);
		//printf("t%f\n", t);
		if(nlen > max)
			t = t2; 
		point = v_add(&r->start, &r->dir);
		point = v_scale(t, &point);
		len = v_sub(&point, p->obj_coord);
		nlen = length(len);
		if(nlen > max)
			return(NO_HIT);
		else
		{
			if(t>0)
			{
			//printf("t%f\n", t);
			return(t);
			}

		}
		
	}
	return (NO_HIT);
}


float ray_plane(t_ray *r, t_obj *p, t_vec obj_coord)
{

	// t_vec norm_dir = normalize(&r->dir);
	// t_vec norm_coord = normalize(&obj_coord);
	t_vec l = v_add(&r->start, &r->dir);
	t_vec point = v_sub(&l, &obj_coord);
	l = normalize(&l);
	point = normalize(&point);
	float denom = dot_p(p->obj_norm, &point);
	
	//printf("denom:%f\n", denom);
	if(denom > 1e-9)
	{
		t_vec p1 = v_sub(&point, p->obj_norm);
		p1 = normalize(&p1);
		float time = dot_p(&p1, &l) /  denom;
		if(time > 0)
		{
		//printf("time:%f\n", time);
		return(time * 100);
		}
	}
	return (NO_HIT);
}
