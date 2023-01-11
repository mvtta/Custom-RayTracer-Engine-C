/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:46 by user              #+#    #+#             */
/*   Updated: 2022/09/04 12:18:39 by user             ###   ########.fr       */
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

	t_vec d = v_add(r->start, r->dir);
	t_vec dist = v_sub(&obj_coord, &d);

	float radius = (s->diameter) / 2;
	float a = dot_p(r->dir, r->dir);
	float b = 2.0 * dot_p(r->dir, &dist);
	float c = dot_p(&dist, &dist) - (radius * radius);
	float discr = b * b - 4 * a * c;
	if (discr >= 0)
	{
		if (discr == 0)
		{
			float t0 = -0.5 * b / a;
			return (t0);
		}
		// float q = MAX(-0.5 * (b + sqrftf(discr)), -0.5 * (b - sqrftf(discr)));
		float t1 = (-b - sqrtf(discr)) / (2 * a);
		float t2 = (-b + sqrtf(discr)) / (2 * a);
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
			// printf("\tt1: %f\n", t1);
			return (t1);
		}
	}
	return (NO_HIT);
}
/*
float ray_cy(t_ray *r, t_obj *c, t_vec obj_coord)
{
	t_vec pa;
	t_vec ba;
	t_vec p = v_add(r->start, r->dir);
	t_vec a = obj_coord;
	t_vec b = v_scale(c->height, c->obj_norm);

	pa = v_add(&p, &a);
	ba = v_add(&b, &a);
	float baba = dot_p(&ba,&ba);
	float paba = dot_p(&pa,&ba);

	t_vec x_aux1 = v_scale(baba, &pa);
	t_vec x_aux2 = v_scale(paba, &ba);
	x_aux1 = v_sub(&x_aux1, &x_aux2);
	float x = length(x_aux1) - (c->diameter / 2 ) * baba;

	float y = fabs(paba-baba*0.5)-baba*0.5;
	float x2 = x*x;
	float y2 = y*y*baba;
	float d =  x2 * x2 - (y * y2);
	if (d >= 0)
	{
		float t1 = (-x2 - sqrtf(d)) / (2 * y);
		float t2 = (-x2 + sqrtf(d)) / (2 * y);
		if (t1 > t2)
		{
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		if (t1 < 0)
			t1 = t2;
		return(t1);
	}
		return(NO_HIT);
}
*/
// infinite plain cylinder

/* float ray_cy(t_ray *r, t_obj *p, t_vec obj_coord)
{
	t_vec pa;
	t_vec pb;

	pa = obj_coord;
	pb = v_scale(p->height, p->obj_norm);
	pb = v_add(&pa, &pa);
	//pb = v_3(pa.x + p->height, pa.y, pa.z);

	float radi = sqrt(p->diameter);
	t_vec ca = v_add(&pa, &pb);
	t_vec oc = v_add(r->start, &pa);
	float caca = dot_p(&ca, &ca);
	float card = dot_p(&ca, r->dir);
	float caoc = dot_p(&ca, &oc);

	float a = caca - (card * card);
	float b = caca * dot_p(&oc, r->dir) - caoc * card;
	float c = caca * dot_p(&oc, r->dir) - (caoc * caoc) - radi * radi * caca;


	0≤(𝐩−𝐱1)⋅(𝐱2−𝐱1)≤(𝐱2−𝐱1)⋅(𝐱2−𝐱1).
	
	float h = b * b - (a * c);
	if (h < 0)
		return(NO_HIT);
	h = sqrt(h);
	float t = (-b - (h)) / (a);
	return(t);
} */

float ray_cy(t_ray *r, t_obj *p, t_vec obj_coord)
{
	t_vec pa;
	t_vec pb;
	t_vec unicam = v_add(r->start, r->dir);
	t_vec x1 = v_sub(&obj_coord, &unicam);
	pa = v_add(&unicam, &obj_coord);
	// pb = project_m(pa, *p->obj_norm);
	/* 	partial rot
	pb = v_scale(p->height, p->obj_norm);
	pb = (&pa, &pb); */
	// pb = v_scale(p->height, p->obj_norm);
	// pb = v_3(p->height * p->obj_norm->x, p->height * p->obj_norm->y, p->height * p->obj_norm->z);
	pb = v_scale(p->height, p->obj_norm);
	t_vec x2 = v_add(&unicam, &pb);	
	pb = v_add(&pa, &pb);
	// inverted these two (up) result is the same why ?
	float radius = sqrt(p->diameter);

	float a = sqr(r->dir->x) + sqr(r->dir->z);
	float b = (r->dir->x * (r->start->x - pa.x)) + (r->dir->z) * (r->start->z - pa.z);
	float c = (r->start->x - pa.x) * (r->start->x - pa.x) + (r->start->z - pa.z) * (r->start->z - pa.z) - (radius * radius);
	float discr = b * b - (a * c);
	if (discr >= 0)
	{
		// float q = MAX(-0.5 * (b + sqrftf(discr)), -0.5 * (b - sqrftf(discr)));
		float t1 = (-b - sqrtf(discr)) / (2 * a);
		float t2 = (-b + sqrtf(discr)) / (2 * a);
		if (t1 > t2)
		{
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		if (t1 < 0)
			t1 = t2;
		t_vec w = v_scale(t1, r->dir);
		w = v_add(r->start, &w);
		/* this works without rotation or caps */
		/* 		if(pa.y <= w.y && pb.y >= w.y)
					return(t1); */
		/* 		attempt to use this formula
				www.math.stackexchange.com/questions/3248356/calculating-ray-cylinder-intersection-points
				|(𝐱(𝑡)−𝐱1)×(𝐱(𝑡)−𝐱2)|2|𝐱1−𝐱2|2=𝑟2. */
		t_vec p = v_add(r->start, r->dir);
		t_vec xtpa = v_sub(&w, &pa);
		t_vec xtpb = v_sub(&w, &pb);
		t_vec axis = v_sub(&pa, &pb);
		//t_vec inv_axis = v_sub(&pb, &pa);
		/* tweek here for rot */
		// float numer = length(cross_p(xtpb, xtpa));
		float numer = length(cross_p(xtpa, xtpb));
		float denom = length(axis);
		if (numer / denom == sqr(radius))
			return (t1);
/* 		t_vec term_1 = v_sub(&p, &xtpa);
		float bounding1 = dot_p(&term_1, &inv_axis);
		float bounding2 = dot_p(&inv_axis, &inv_axis);
		if (bounding1 <= denom && bounding2 <= denom)
			return (t1);
			 */
		//0≤(𝐩−𝐱1)⋅(𝐱2−𝐱1)≤(𝐱2−𝐱1)⋅(𝐱2−𝐱1).
		t_vec y1 = v_sub(&p, &x1);
		t_vec y2 = v_sub(&x2, &x1);
		float yp = dot_p(&y1, &y2);
		float zp = dot_p(&y2, &y2); 
		if (0 <= yp && yp <= zp)
			return (t1);
		return (t1);
		/* 	caps */
		/* make caps */
	}
	return (NO_HIT);
}

float ray_plane(t_ray *r, t_obj *p)
{

	float t;
	//float o;
	//float pp;
	float v;
	float d;
	p->test = v_add(r->start, r->dir);
	//pp = solve_q(p, *p->obj_coord);
	//o = solve_q(p, *r->start);
	v = solve_q(p, *r->dir);
	d = solve_d(p, p->test);
	t = (d / v);
	if (v > 1e-9)
	{
		if (t < 0)
			t *= -1;
		return (t);
	}
	return (NO_HIT);
}
