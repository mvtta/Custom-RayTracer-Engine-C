/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:51:10 by user              #+#    #+#             */
/*   Updated: 2022/06/06 19:06:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "control.h"

int	light_up(int keycode, t_frame *rt)
{
	printf("* * * * LIGHT UP * * * * \n[%d]\n", keycode);
	rt->scene->l->light_coord->y -= 10;
	mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr, rt->window_w, rt->window_h);
	rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr,
			&rt->obj_img.bits_per_pixel, &rt->obj_img.line_length,
			&rt->obj_img.endian);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	render (rt);
	return (0);
}

int	light_down(int keycode, t_frame *rt)
{
	printf("* * * * LIGHT DOWN * * * * \n[%d]\n", keycode);
	rt->scene->l->light_coord->y += 10;
	mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr,
			rt->window_w,
			rt->window_h);
	rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr,
			&rt->obj_img.bits_per_pixel,
			&rt->obj_img.line_length,
			&rt->obj_img.endian);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	render (rt);
	return (0);
}

int	light_left(int keycode, t_frame *rt)
{
	printf("* * * * LIGHT LEFT * * * * \n[%d]\n", keycode);
	rt->scene->l->light_coord->x += 10;
	mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr,
			rt->window_w,
			rt->window_h);
	rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr,
			&rt->obj_img.bits_per_pixel,
			&rt->obj_img.line_length,
			&rt->obj_img.endian);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	render (rt);
	return (0);
}

int	light_right(int keycode, t_frame *rt)
{
	printf("* * * * LIGHT RIGHT * * * * \n[%d]\n", keycode);
	rt->scene->l->light_coord->x -= 10;
	mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr,
			rt->window_w, rt->window_h);
	rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr,
			&rt->obj_img.bits_per_pixel,
			&rt->obj_img.line_length,
			&rt->obj_img.endian);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	render (rt);
	return (0);
}
