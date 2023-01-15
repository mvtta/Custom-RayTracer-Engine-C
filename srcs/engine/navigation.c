/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:12:12 by user              #+#    #+#             */
/*   Updated: 2022/06/06 19:08:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int	cam_up(int keycode, t_frame *rt)
{
	printf("moving camera on y ↑\n\n");
	rt->scene->c->cam_coord->y -= 10;
	mlx_destroy_image(rt->mlx_ptr, rt->obj_img.img_ptr);
	rt->obj_img.img_ptr = mlx_new_image(rt->mlx_ptr, rt->window_w, rt->window_h);
	rt->obj_img.data = (int *)mlx_get_data_addr(rt->obj_img.img_ptr,
			&rt->obj_img.bits_per_pixel, &rt->obj_img.line_length,
			&rt->obj_img.endian);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	render (rt);
	return (0);
}

int	cam_down(int keycode, t_frame *rt)
{
	printf("moving camera on y ↓\n\n");
	rt->scene->c->cam_coord->y += 10;
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

int	cam_left(int keycode, t_frame *rt)
{
	printf("moving camera on x <- \n\n");
	rt->scene->c->cam_coord->x += 10;
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

int	cam_right(int keycode, t_frame *rt)
{
	printf("moving camera on x -> \n\n");
	rt->scene->c->cam_coord->x -= 10;
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
