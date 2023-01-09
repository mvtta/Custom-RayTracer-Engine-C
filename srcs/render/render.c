/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/06/16 19:50:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

static void	render_status(void)
{
    printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀", 'g');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 'y');
	printi("		Rendering . . .", 'y');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 'y');
    printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀", 'g');
}

void iterate_obj(t_frame *rt, t_ray *prime, int x, int y)
{
    t_color volume;
    t_obj *current;
    float hit;
    float fh;
    float fl;
    float fn;
    float ff;
    float dof;

    fl = rt->scene->c->focal_l;
    fh = get_hyperfocal_dist(fl, 0.025, 0.02);
    fn = get_near_dof(fl);
    ff = get_far_dof(fl);
    dof = get_dof_range(fn, ff);

    current = rt->objs_first;
    int i = 0;
    while (++i <= rt->nbr_objs)
    {
        hit = compute_obj(prime, current);
        if (hit != NO_HIT)
        {
            rt->record.latest_t = hit;
            volume = standard_re(rt, prime, current);
            if(rt->auto_focus == 'm')
            {
                if (hit != fh || hit < fl || hit > fl)
                {
                    rt->out_of_focus = 9;
                    unsigned int new = apply_blur(rt, x, y);
                    my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h - 1) - y, new);
                    depth_map(rt, x, y, new);
                } 
            }
            else
                my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h - 1) - y, volume.hex);
            depth_map(rt, x, y, volume.hex);
        }
        current = current->next;
    }
}

float compute_obj(t_ray *ray, t_obj *obj)
{
    float t;
    if (obj->id1 == PLANE)
        t = ray_plane(ray, obj);
    if (obj->id1 == SPHERE)
        t = ray_sphere(ray, obj, *obj->obj_coord);
    if (obj->id1 == 'c')
        t = ray_cy(ray, obj, *obj->obj_coord);
    return (t);
}

static void fake_init(t_ray **r)
{
    *r = malloc(sizeof(t_ray));
    (*r)->start = malloc(sizeof(t_vec));
    (*r)->dir = malloc(sizeof(t_vec));
    (*r)->norm = malloc(sizeof(t_vec));
    (*r)->len = 0;
}

int render(t_frame *rt)
{
    //compose_caption(rt);
    t_ray *ray;
    float x;
    float y = 0;
    fake_init(&ray);
    ray->start = ro_3(ray, rt->scene->c->cam_coord);
    (*ray->dir) = v_sub(rt->scene->c->cam_coord, rt->scene->c->cam_norm);
    ray->dir->z = ndc(rt, rt->scene->c->cam_norm->z, 'z');
    (*ray->norm) = normalize(rt->scene->c->cam_norm);
    render_status();
    while (y < (float)rt->window_h - 1)
    {
        x = 0;
        ray->start->y = rt->scene->c->cam_coord->y;
        ray->dir->y = ndc(rt, y, 'y');
        while (x < (float)rt->window_w - 1)
        {
            ray->start->x = rt->scene->c->cam_coord->x;
            ray->dir->x = ndc(rt, x, 'x');
            iterate_obj(rt, ray, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);
    /* 
    * caption:
                ~   lens
                ~   number of objects
                ~   focus 
    compose_caption(&rt);
    mlx_string_put(rt->mlx_ptr, rt->win_ptr, 100, 100, 3136671, "ESCREVER\n");
    * focal distance marked:
                ~   closest
                ~   furthest
    focal_marks(&rt);
    mlx_string_put(rt->mlx_ptr, rt->win_ptr, 100, 100, 3136671, "+"
    *
    */

    return (0);

}
