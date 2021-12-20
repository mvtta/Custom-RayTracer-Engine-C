/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/20 21:49:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_obj(t_ray *ray, t_obj *obj)
{
    float t;
    // compute_sphere(obj, rt);
    if (obj->id1 == PLANE)
        t = ray_plane(ray, obj, *obj->obj_coord);
    if (obj->id1 == SPHERE)
        t =  ray_sphere(ray, obj, *obj->obj_coord);
   // printf("\t t: %f\n", t);
    //printf("\t id1: %c\n", obj->id1);
    return(t);
}


int render(t_frame *rt)
{
    t_color volume;
    t_obj *current;
    t_ray ray;
    float hit;
    int x;
    int y = 0;

    ray.dir.z = 1;
    ray.start.z = rt->scene->cam_coord->z;
    while (y < rt->window_h)
    {
        x = 0;
        ray.start.y = rt->scene->cam_coord->y;
        ray.dir.y = -(2 * (y + 0.5) / (float)rt->window_h - 1) * tan(rt->scene->fov / 2);
        while (x < rt->window_w)
        {
            ray.start.x = rt->scene->cam_coord->x;
            ray.dir.x = (2 * (x + 0.5) / (float)rt->window_w - 1) * tan(rt->scene->fov / 2) * rt->window_w / (float)rt->window_h;
            int i = 0;
            current = rt->objs_first;
            //printf("\t nbr of objs: %d\n", rt->nbr_objs);
            while (++i <= rt->nbr_objs)
            {
                hit = compute_obj(&ray, current);
                if(hit != NO_HIT)
                {
                    volume = standard_re(rt, &ray, hit, current);
                    mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, volume.hex);
                }
                current = current->next;
                printf("\ti: %d\n", i);
            }
        x++;
        }
    y++;
    }
    return (0);
}
