/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:44:01 by user              #+#    #+#             */
/*   Updated: 2021/05/18 18:46:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"

double	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, t_quadric *q)
{
	t_vector	dist;

	dist = vec_diff(ray->origin, sphere->cord);
	q->a = vec_dot(ray->dir, ray->dir);
	q->b = 2 * vec_dot(ray->dir, dist);
	q->c = vec_dot(dist, dist) - (sphere->radius * sphere->radius);
	q->discriminant = (q->b * q->b) - 4 * (q->a * q->c);
	if (q->discriminant < 0)
	{
		q->t[0] = INFINITY;
		q->t[1] = INFINITY;
		return (INFINITY);
	}
	q->t[0] = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
	q->t[1] = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
	if (q->t[0] < q->t[1])
		return (q->t[0]);
	if (q->t[0] > q->t[1])
		return (q->t[1]);
	return (INFINITY);
}

void	sphere_intersec_color(t_sphere *sphere, t_ray *ray, t_scene scene)
{
	double			t_;
	t_vector		normal;
	t_quadric		q;

	t_ = sphere_intersec_equation(ray, sphere, &q);
	if (t_ > ray->dir.z && t_ < INFINITY && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = sphere;
		ray->ray_color = sphere->color;
		ray->ray_n_t = ray_equation(ray, ray->ray_t);
		normal = vec_diff(ray->ray_n_t, sphere->cord);
		normal = normalize(normal);
		ray->ray_color = color_multipli(color_range1(ray->ray_color),
		compute_light(*ray, normal, scene, ray->obj));
	}
}

void	raytosphere(t_ray *ray, t_sphere sphere)
{
		sphere_intersec_color(&sphere, ray, sphere);
}