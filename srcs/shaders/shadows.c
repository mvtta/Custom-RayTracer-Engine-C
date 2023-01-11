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

    /*
    Note:
    this: d = v_add(ray->start, ray->dir); = to ...
    this: t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);
    fun, means math is right
    */

    /* 
    Math :
    1. get the camera -> obj vector 
        by: 	t_vec d = v_add(ray->start, ray->dir);
                t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);
    2. get camera -> light vector
        by:     t_vec ldir = v_add(rt->scene->l->light_coord, ray->start);


     */
	//t_vec d = v_add(ray->start, ray->dir);
    t_vec to_hit =  v_scale(rt->record.latest_t, ray->dir);

    /* Rename : t_vec test renamed ldir for test convenience  */
    t_vec ldir = v_sub(rt->scene->l->light_coord, ray->start);
    //t_vec norm = normal_2p(&to_hit, obj->obj_coord);
/*     
    Test:
    Sub ldir by test and see if diff is enough to fix shadow:
        both vector operations are giving analogous values: 
    TEST PERFORMED to verfy such values:
    t_vec test = v_sub(rt->scene->l->light_coord, ray->start);
    t_vec ldir = v_add(rt->scene->l->light_coord, ray->start);
    print_vector(test, "1 - sub light position and camera");
    print_vector(ldir, "2 - add light position and camera");
    t_vec testing_minus_form_test = v_add(&test, &to_hit);
    t_vec testing_minus_form_ldir = v_add(&ldir, &to_hit);
    print_vector(testing_minus_form_test, "1 - testing_minus_form_test");
    print_vector(testing_minus_form_ldir, "1 - testing_minus_form_ldir");
     */
    //exit(0);
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


