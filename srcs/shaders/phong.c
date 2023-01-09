/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:39:38 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/06/15 22:38:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

double phong(t_frame *rt, t_ray *ray, t_obj *obj)
{
    float   spec;
    double  attenuation;
    double  total;
    double  camera;
    t_vec   hit;
    t_vec   hit_norm;
    t_vec   v;
    t_vec   l;
    t_vec   h;

    hit = v_scale(rt->record.latest_t, ray->dir);
    t_vec center = v_sub(ray->start, obj->obj_coord);
    l = v_sub(rt->scene->l->light_coord, ray->start);
    l = v_add(&l, &hit);
    l = v_scale(1, &l);
    hit_norm = v_sub(&hit, &center);
    //hit_norm = *obj->obj_norm;
    v = hit;
    v = normalize(&v);
    camera = length(l);
    l = normalize(&l);
    h = v_add(&v, &l);
    attenuation = sqr(1 / camera);
    hit_norm = normalize(&hit_norm);
    h = normalize(&h);
    float dot = dot_p(&h, &hit_norm);
    if (dot < 0)
        return (0);
    spec = pow(dot,10) * attenuation * 40;
    total = c_clamp(spec, 0.0, 1);
    return (total);
    }
    /*
        ~ 48 is unity's specular reflection factor
        ~ 4.8 is standardize value
    */
