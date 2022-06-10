/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:42:44 by user              #+#    #+#             */
/*   Updated: 2022/06/06 18:45:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "control.h"

int    zoom_in(int keycode, t_frame *rt)
{
    printf("* * * * ZOOMING IN * * * * \n[%d\n]", keycode);
    rt->scene->c->cam_coord->z += 10;
    mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
    rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr, \
        rt->window_w, rt->window_h);
    rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr, \
        &rt->obj_img.bits_per_pixel, \
        &rt->obj_img.line_length, \
        &rt->obj_img.endian);
    mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
    /* (COMMENT LINE ABOVE FOR DOUBLE EXPOSURE) */
    render(rt);
    return(0);
}

int    zoom_out(int keycode, t_frame *rt)
{
    printf("* * * * ZOOMING OUT * * * * \n[%d\n]", keycode);
    rt->scene->c->cam_coord->z += 10;
    mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
    rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr, \
        rt->window_w, \
        rt->window_h);
    rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr, \
        &rt->obj_img.bits_per_pixel, \
        &rt->obj_img.line_length, \
        &rt->obj_img.endian);
    mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
    /* (COMMENT LINE ABOVE FOR DOUBLE EXPOSURE) */
    render(rt);
    return(0);
}
