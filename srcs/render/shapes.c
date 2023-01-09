/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:28:27 by user              #+#    #+#             */
/*   Updated: 2022/08/10 11:24:34 by user             ###   ########.fr       */
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
    
t_vec project_m(t_vec src, t_vec rot)
{
    float m[3][3];
    t_vec v;
    m[0][0] = -rot.x;
    m[0][1] = 0;
    m[0][2] = 0;
    m[1][0] = 0;
    m[1][1] = -rot.y;
    m[1][2] = 0;
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = -rot.z;

    v.x = (src.x * m[0][0] + src.y * m[0][1] + src.z * m[0][2]);
    v.y = (src.x * m[1][0] + src.y * m[1][1] + src.z * m[1][2]);
    v.z = src.x * m[2][0] + src.y * m[2][1] + src.z * m[2][2];

    return(v);
 
}