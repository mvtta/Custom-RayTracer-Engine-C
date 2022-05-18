/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:28:27 by user              #+#    #+#             */
/*   Updated: 2022/05/17 11:54:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* t_axis gen_axis(t_obj *shape, t_ray *ray)
{
    t_axis *axis = NULL;
    axis->center = v_3(shape->obj_coord->x, shape->obj_norm->y, shape->obj_norm->z);
    axis->bot = v_3(shape->obj_coord->x, shape->obj_coord->y - (shape->height / 2), shape->obj_coord->z);
    axis->top = v_add(&axis->bot, shape->obj_norm);
    axis->top = v_scale(shape->height, &axis->top);
    axis->edge = v_3(axis->center.x + (shape->diameter / 2), axis->center.y, axis->center.z);
    exit(0);
} */
    