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

/* notation:
* Standard line eq:
* 			𝑎 𝑥 + 𝑏 𝑦 + 𝑐 = 0
* The equation of the line can also be realized as a
* dot product of two vectors as
* Standard eq plane :
* 			𝑎 𝑥 + 𝑏 𝑦 + 𝑐 𝑧 + 𝑑 = 0
* Plane from 2 points:
* 			𝑎 ( 𝑥 − 𝑥 ) + 𝑏 ( 𝑦 − 𝑦 ) + 𝑐 ( 𝑧 − 𝑧 ) = 0
* Normal vector: cross_p
*
* ray_plane intersections:
* point in plane: (p−p0)⋅n=0
* ray :
*			l0+l∗t=p
* two eqs in one : (
			l0+l∗t−p0)⋅n=0
* compute t:
* 			t = =−(l0−p0)⋅n/ l⋅n
* 	-------------------------------------
* 	l0 -> is the origin of the ray
* 	l -> is the ray direction
* 	p0 -> point far away in plane
*	n -> normm vec
*/

float ray_sphere(t_ray *r, t_obj *s, t_vec obj_coord)
{

	t_vec d;
	t_vec dist;
	float radius;
	float a;
	float b;
	float c;
	float discr;

	d = v_add(r->start, r->dir);
	dist = v_sub(&obj_coord, &d);
	radius = (s->diameter) / 2;
	a = dot_p(r->dir, r->dir);
	b = 2.0 * dot_p(r->dir, &dist);
	c = dot_p(&dist, &dist) - (radius * radius);
	discr = b * b - 4 * a * c;

	if (discr >= 0)
	{
		if (discr == 0)
		{
			float t0 = -0.5 * b / a;
			return (t0);
		}
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
			return (t1);
	}
	return (NO_HIT);
}

float ray_cy(t_ray *r, t_obj *c, t_vec obj_coord)
{
	t_vec ao;
	t_vec ab;
	t_vec a = obj_coord;
	t_vec b = v_scale(c->height, c->obj_norm);

	b = v_add(&a, &b);

	t_vec o = v_add(r->start, r->dir);

	ao = v_add(&o, &a);

	ab = v_add(&b, &a);
	t_vec n_ao = normalize(&ao);

	t_vec n_ab = normalize(&ab);

	t_vec ao_x_ab = cross_p(n_ao, n_ab);
	t_vec v_x_ab = cross_p(*r->dir, n_ab);

	double ab2 = dot_p(&ab, &ab);

	float dot_product_a = dot_p(&v_x_ab, &v_x_ab);
	float dot_product_b = dot_p(&v_x_ab, &ao_x_ab) * 2;
	float dot_product_c = dot_p(&ao_x_ab, &ao_x_ab) - c->diameter * ab2;

	float d = dot_product_b * dot_product_b - 4 * dot_product_a * dot_product_c;

	// a*t^2 + b*t + c = 0
	//t = (-b ± sqrt(b^2 - 4 a c))/(2 a) (a!=0)
	if (d < 0)
		return(NO_HIT);
	
	
/* 	INFINITE CYLINDER */
	
	double t = - dot_product_b - (sqrt(d)) / 2 * dot_product_a;
	double t1 = - dot_product_b + (sqrt(d)) /  2 * dot_product_a;
	if (t1 <= c->diameter)
		return(t1);
		//printf("t:	%f --- t1:	%f\n", t, t1);
/* 	if(t > 0 && t <= c->diameter)
	{
		float c_form = pow(c->obj_coord->x * t, 2) + pow(c->obj_coord->y * t,2);
		if (c_form <= c->diameter)
		{

			return(t);
		}
	}  */
	return(NO_HIT);

	/* 	if (d >= 0)
		{
			double q = (dot_product_a * t) * 2  + dot_product_b * t + dot_product_c;
			if (t > 0)
			{
				double cylinder_form = (o.x * o.x) + (o.y * o.y) + (o.x);
				if (cylinder_form == 1)
					return(t);
			} */

	// double time = - dot_product_b - sqrt(d) / (2 * dot_product_a);
// t_vec intersection = v_scale(time, &o);
// d = dot_product_a * (time * time) + dot_product_b * (time) + dot_product_c;
//  p is in cy if (P-A)X(B-A) * r^2 B-A
//  or
// at^2 + bt +c 0 0
}

/* Ray : P(t) = O + V * t
// Cylinder [O, D, r].
// point Q on cylinder if ((Q - O) x D)^2 = r^2
//// Cylinder [A, B, r].
// Point P on infinite cylinder if ((P - A) x (B - A))^2 = r^2 * (B - A)^2
// expand : ((O - A) x (B - A) + t * (V x (B - A)))^2 = r^2 * (B - A)^2
// equation in the form (X + t * Y)^2 = d
// where :
//  X = (O - A) x (B - A)
//  Y = V x (B - A)
//  d = r^2 * (B - A)^2
// expand the equation :
// t^2 * (Y . Y) + t * (2 * (X . Y)) + (X . X) - d = 0
// => second order equation in the form : a*t^2 + b*t + c = 0 where
// a = (Y . Y)
// b = 2 * (X . Y)
// c = (X . X) - d
//--------------------------------------------------------------------------
Vector AB = (B - A);
Vector AO = (O - A);
Vector AOxAB = (AO ^ AB);
// cross productVector VxAB  = (V ^ AB);
// cross productfloat  ab2   = (AB * AB);
// dot productfloat a      = (VxAB * VxAB);
// dot productfloat b      = 2 * (VxAB * AOxAB);
// dot productfloat c      = (AOxAB * AOxAB) - (r*r * ab2);
// solve second order equation : a*t^2 + b*t + c = 0 */

// infinite plain cylinder

/* float ray_cy(t_ray *r, t_obj *p, t_vec obj_coord)
{
	t_vec pa;
	t_vec pb;

	pa = obj_coord;
	pb = v_scale(p->height, p->obj_norm);
	pb = v_add(&pa, &pa);
	pb = v_3(pa.x + p->height, pa.y, pa.z);

	float radi = sqrt(p->diameter);
	t_vec ca = v_add(&pa, &pb);
	t_vec oc = v_add(r->start, &pa);
	float caca = dot_p(&ca, &ca);
	float card = dot_p(&ca, r->dir);
	float caoc = dot_p(&ca, &oc);

	float a = caca - (card * card);
	float b = caca * dot_p(&oc, r->dir) - caoc * card;
	float c = caca * dot_p(&oc, r->dir) - (caoc * caoc) - radi * radi;;

	float h = b * b - 4 * (a * c);
	if (h >= 0)
	{
		float t = (-b - (h)) / (a);
		float t1 = (+b - (h)) / (a);
		return(t>t1?t:t1);
	}
	if(h != 1)
	{
		float t = (-b - (h)) / (a);
		float t1 = (+b - (h)) / (a);
		return(t>t1?t:t1);
	}
	if (h < 0)
		return(NO_HIT);
	return(NO_HIT);
} */

float ray_plane(t_ray *r, t_obj *p)
{

	float t;
	// float o;
	// float pp;
	float v;
	float d;
	p->test = v_add(r->start, r->dir);
	// pp = solve_q(p, *p->obj_coord);
	// o = solve_q(p, *r->start);
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
