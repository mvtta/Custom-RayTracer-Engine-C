/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:07:34 by user              #+#    #+#             */
/*   Updated: 2022/06/15 22:44:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

double ambient(t_frame *rt, t_ray *ray, t_obj *obj)
{
    double difuse;
    t_vec hit;
    t_vec hit_norm;
    t_vec l;

    hit = v_scale(rt->record.latest_t, ray->dir);
    //hit = v_sub(ray->start, &hit);
    t_vec center = v_sub(ray->start, obj->obj_coord);
    if (obj->id1 == SPHERE)
        hit_norm = v_sub(&hit, &center);
    else
        hit_norm = *obj->obj_norm;
    l = v_add(ray->start, rt->scene->l->light_coord);
    l = v_sub(&l, &hit);
    l = v_scale(1, &l);
    
    l = normalize(&l);
    hit_norm = normalize(&hit_norm);

   difuse = dot_p(&hit_norm, &l);
   if (difuse < 0)
    return(0);
    return ((difuse));
}
