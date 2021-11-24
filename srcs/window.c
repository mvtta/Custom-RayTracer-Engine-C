/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:53:53 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/24 17:03:06 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	map_to_img(t_data data, int x, int y, int color)
{
	data.data[(y * data.line_length + x * (data.bits_per_pixel / 8) / 4)] = color;
}

void window_init(t_frame *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->window_w, rt->window_h, "A cool rt");
}