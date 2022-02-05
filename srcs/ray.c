/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:02:38 by user              #+#    #+#             */
/*   Updated: 2022/02/05 20:44:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_ray *ray_init(void)
{
    t_ray *ray;
    ray = malloc(sizeof(t_ray));
    ray->start = NULL;
    ray->dir = NULL;
    ray->len = 0;
    return (ray);
}

t_ray *ray_prime(t_ray *ray, t_vec *origin)
{
    ray = ray_init();
    ray->start->x = origin->x;
    ray->start->y = origin->y;
    ray->start->z = origin->z;
    return(ray);
}

t_ray ray_from_to(t_vec *point_origin, t_vec *point_direction)
{
    t_ray *new;
    new = NULL;
    new = ray_init();
    *new->start = v_3(point_origin->x, point_origin->y, point_origin->z);
    *new->dir = v_3(point_direction->x, point_direction->y, point_direction->z);
    *new->norm = normalize(new->dir);
    new->len = length(*new->dir);
    return(*new);
}

/* t_vec ray_time(t_vec point_origin, t_vec point_direction)
{

}

t_vec ray_invert_direction(t_vec point_origin, t_vec point_direction)
{

} */