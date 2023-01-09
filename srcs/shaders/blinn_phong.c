/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blinn_phong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:40:54 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/06/16 23:26:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

double blinn_phong(t_frame *rt, t_ray *ray, t_obj *obj)
{
    float spec;
    double attenuation;
    double total;
    double camera;
    // double ratio;

    t_vec hit;
    t_vec hit_norm;
    t_vec v;
    t_vec l;
    t_vec h;

    hit = v_scale(rt->record.latest_t, ray->dir);
    t_vec center = v_sub(ray->start, obj->obj_coord);
    l = v_sub(rt->scene->l->light_coord, ray->start);
    l = v_add(&l, &hit);
    l = v_scale(1, &l);

    if (obj->id1 == SPHERE)
        hit_norm = v_sub(&hit, &center);
    else
        hit_norm = *obj->obj_norm;
    v = hit;
    v = normalize(&v);
    camera = length(l);
    l = normalize(&l);
    h = v_add(&v, &l);
    attenuation = 1 / sqr(camera);
    hit_norm = normalize(&hit_norm);
    h = normalize(&h);
    float dot = dot_p(&h, &hit_norm);
    if (dot < 0 || dot > 1)
        return (0);
   spec = pow(dot, 100) * attenuation * 80;

    total = c_clamp(spec, 0.0, 1);
    return (total);
}
