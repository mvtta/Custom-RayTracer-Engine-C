/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:53:53 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/04/22 01:48:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	map_to_img(t_data data, int x, int y, int color)
{
	data.data[(y * data.line_length + x * (data.bits_per_pixel / 8) / 4)] = color;
}
/* ~ 35mm Full Format Focal Len by FOV rapid table
? | FOV | DOF   | CIRCLEC D-A | LENS | GROUP      | VISUAL
* | 2   | 50    | 0.36 - 0.03 | 1131 | SUPER TELE | SCALE++ FAR FOCUS
* | 20  | 60    |             | 102  | TELE       | SCALE+ FAR FOCUS
* | 30  | 5     |             | 67   | MEDIUM TELE| MEDIUM SCALE 
* | 50  | 5     |             | 38   | standard   |
* | 60  | 5     |             | 31   | WIDE ANGLE |
* | 80  | 5     |       4     | 21   | SUPER WIDE |
* | 100 | 5     |             | 15   | SUPER WIDE | */
void window_init(t_frame *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->window_w, rt->window_h, "format : 35mm Film | Hfov: 50 | lens: 38mm | depth of field: yes");
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr, rt->window_w, rt->window_h);
    rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr, &rt->obj_img.bits_per_pixel, &rt->obj_img.line_length, &rt->obj_img.endian);
    ft_bzero(rt->obj_img.data, sizeof(&rt->obj_img.data));
    mlx_hook(rt->win_ptr, 2, 53, key_kill, rt);
    mlx_hook(rt->win_ptr, 17, 1216, key_kill, rt);
}

void background_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->bkg_img.img_ptr, 0, 0);
}

void obj_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
    size_t offset;

    offset = ((y * data->line_length + x * data->bits_per_pixel / 8) / 4);
    data->data[offset] = color;
}