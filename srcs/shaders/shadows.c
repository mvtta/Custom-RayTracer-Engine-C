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

int in_shadow(t_frame *rt, t_ray *ray, t_obj *obj)
{

    t_obj *current;
    t_ray *shadow;
    float hit;
    //float bias = 1e-4;
    int i = -1;
    ray_init(&shadow);
    t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);
    //t_vec norm = normal_2p(&to_hit, obj->obj_coord);
    t_vec ldir = v_add(rt->scene->l->light_coord, ray->start);
    ldir = v_add(&ldir, &to_hit);
//    norm = v_scale(1, &norm);

   // t_vec dev = v_3(0.2, 0.3, 0.1);
   // ldir = v_add(&dev,&ldir);
    //ldir = v_scale(0.07, &ldir);
    
    shadow->start = rd_3(shadow, &to_hit);
    shadow->dir = ro_3(shadow, &ldir);
/* 
    *shadow->start = normalize(shadow->start);
    *shadow->dir = normalize(shadow->dir); */
    
    current = rt->objs_first;
    while (++i < rt->nbr_objs)
    {
       
        hit = compute_obj(shadow, current);
        if (hit != NO_HIT && current->id2 != 'r' && obj->id2 != current->id2)
        {
           // printf("hit:%f\n", hit);
            //return(0);
            return(hit);
        }
        current = current->next;
    }
    return(0);
}


