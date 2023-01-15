/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:51:35 by user              #+#    #+#             */
/*   Updated: 2022/06/17 01:46:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
/*
 * Note:
 * this: d = v_add(ray->start, ray->dir); = to ...
 * this: t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);
 * fun, means math is right
 */

/*
 * Math :
 * 1. get the camera -> obj vector
 * by: t_vec d = v_add(ray->start, ray->dir);
 * t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);
 * 2. get camera -> light vector
 * by: t_vec ldir = v_add(rt->scene->l->light_coord, ray->start);
 */
 
int in_shadow(t_frame *rt, t_ray *ray, t_obj *obj)
{

    t_obj *current;
    t_ray *shadow;
    float hit;
    float bias;
    int   i;
    t_vec to_hit;
    t_vec ldir;
    t_vec dev;

    ray_init(&shadow);
    
    i = -1;
    bias = 1e-4;
    to_hit = v_scale(rt->record.latest_t, ray->dir);
    ldir = v_add(ray->start, rt->scene->l->light_coord);
    dev = v_3(0.2, 0.3, 0.1);
    ldir = v_add(&dev, &ldir);
    ldir = v_scale(0.07, &ldir);
    shadow->start = &to_hit;
    shadow->dir = &ldir;
    current = rt->objs_first;

    while (++i < rt->nbr_objs)
    {

        hit = compute_obj(shadow, current);
        if (hit != NO_HIT && current->id2 != 'r' && obj->id2 != current->id2)
        {
            return (hit);
        }
        else
            current = current->next;
    }
    return (0);
}
