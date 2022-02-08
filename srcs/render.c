/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/02/07 13:31:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_obj(t_ray *ray, t_obj *obj)
{
    float t;
    if (obj->id1 == PLANE)
        t = ray_plane(ray, obj, *obj->obj_coord);
    if (obj->id1 == SPHERE)
        t = ray_sphere(ray, obj, *obj->obj_coord);
    if (obj->id1 == 'c')
        t = ray_cy(ray, obj, *obj->obj_coord);
    return (t);
}

/*   static void test_ray(t_ray *r, t_vec *o)
{
    // r->start = malloc(sizeof(t_vec));
    r->start = o;
} */

static void fake_init(t_ray **r) {
    *r = malloc(sizeof(t_ray));
    (*r)->start = malloc(sizeof(t_vec));
    (*r)->dir = malloc(sizeof(t_vec));
    (*r)->norm = malloc(sizeof(t_vec));
    (*r)->len = 0;
}
int render(t_frame *rt)
{
    t_color volume;
    t_obj *current;
    t_ray *ray;
    float hit;
    int i;
    float x;
    float y = 0;

    //ray = ray_prime(ray, rt->scene->c->cam_coord);

    // ray = ray_init();
    fake_init(&ray);
    ray->start = ro_3(ray, rt->scene->c->cam_coord);
    ray->norm = rt->scene->c->cam_norm;
    
    //print_vector(*ray->start, "camtest");
    //exit(0);
    // ray->start = ro_3(ray, rt->scene->c->cam_coord);
  // test_ray(ray, rt->scene->c->cam_coord);
   //print_vector(*ray->start, "LALA");
    //exit(0);
    ray->dir->z = ndc(rt, rt->scene->c->cam_coord->z, 'z');
    while (y < (float)rt->window_h - 1)
    {
        x = 0;
        ray->start->y = rt->scene->c->cam_coord->y;
        ray->dir->y = ndc(rt, y, 'y');
        while (x < (float)rt->window_w -1)
        {
            ray->start->x = rt->scene->c->cam_coord->x;
            ray->dir->x = ndc(rt, x, 'x');
            i = 0;
            current = rt->objs_first;
            while (++i <= rt->nbr_objs)
            {
                hit = compute_obj(ray, current);
                if (hit != NO_HIT)
                {
                    rt->record.latest_t = hit;
                    volume = standard_re(rt, ray,current);
                    my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h -1) - y, volume.hex);
                }
                current = current->next;
            }
            x++;
        }
        y++;
    }
    // printf("here\n");
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);

    return (0);
}
