/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/24 17:14:09 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int *dst;

    dst = data->data + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void compute_sphere(t_obj *obj, t_frame *rt)
{
    t_ray ray;
    bool hit;
    int color;
    int x;
    int y;

    ray.dir.x = 0;
    ray.dir.y = 0;
    ray.dir.z = 1;
    x = 0;
    y = 0;

    ray.start.z = 0;
    color = obj->obj_color->hex;

    while (y < rt->window_h)
    {
        ray.start.y = y;
        y++;
        x = 0;
        while (x < rt->window_w)
        {
            ray.start.x = x;
            hit = ray_sphere(&ray, obj);
            if (hit)
            {
                //printf("++");
                mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, 49408);
            }
            x++;
        }
    }
}

void compute_obj(t_obj *obj, t_frame *rt)
{
    compute_sphere(obj, rt);
}

void background_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->bkg_img.img_ptr, 0, 0);
}

void obj_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);
}

int render(t_frame *rt)
{
    create_image(rt, 1, 0);
    compute_obj(rt->objs_first, rt);
    obj_to_window(rt);

    return (0);
    /* put_img_to_window */
}
