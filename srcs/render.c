/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/22 21:34:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_obj(t_ray *ray, t_obj *obj)
{
    float t;
    if (obj->id1 == PLANE)
        t = ray_plane(ray, obj, *obj->obj_coord);
    if (obj->id1 == SPHERE)
        t =  ray_sphere(ray, obj, *obj->obj_coord);
    return(t);
}
/* 		screen.viewport_width = tan(DEG_TO_RAD(c->fov / 2)) * 2;
		screen.viewport_height = screen.viewport_width * \
		RATIO((double)info->all->r->y, (double)info->all->r->x); */

int render(t_frame *rt)
{
    t_color volume;
    t_obj *current;
    t_ray ray;
    float hit;
    int i;
    float x;
    float y = 0;

    ray.dir.z = ndc(rt, ray.dir.z, 'z');
    ray.start.z = rt->scene->cam_coord->z;
    while (y < (float)rt->window_h)
    {
        x = 0;
        ray.start.y = rt->scene->cam_coord->y;
        ray.dir.y = ndc(rt, y, 'y');
        while (x < (float)rt->window_w)
        {
            ray.start.x = rt->scene->cam_coord->x;
            ray.dir.x = ndc(rt, x, 'x');
            i = 0;
            current = rt->objs_first;
            while (++i <= rt->nbr_objs)
            {
                hit = compute_obj(&ray, current);
                if(hit != NO_HIT)
                {
                    //printf("hit: %f\n", hit);
                    volume = standard_re(rt, &ray, hit, current);
                    printf("\tvolume hex in loop: %u\n", volume.hex);
                    //mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, volume.hex);
                    my_mlx_pixel_put(&rt->obj_img, x, y, volume.hex);
                }
                current = current->next;
            }
        x++;
        }
    y++;
    }
    //printf("here\n");
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);

    return (0);
}
