/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:22 by user              #+#    #+#             */
/*   Updated: 2022/05/17 10:06:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_vec *ro_3(t_ray *ray, t_vec *where)
{
    ray->start->x = where->x;
    ray->start->y = where->y;
    ray->start->z = where->z;
    return(ray->start);
}

t_vec *rd_3(t_ray *ray, t_vec *where)
{
    ray->dir->x = where->x;
    ray->dir->y = where->y;
    ray->dir->z = where->z;
    return(ray->dir);
}


double angle_bet_vs(t_vec *v1, t_vec *v2)
{
    float scalar = dot_p(v1, v2);
    float mag1 = length(*v1);
    float mag2 = length(*v2);
    float angle = scalar / (mag1 * mag2);
    // printf("angle should be between 0 & 180: %f\n", acos(angle));
    return (acos(angle));
}

