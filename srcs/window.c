/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:53:53 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/22 18:20:27 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void window_init(void)
{
   void *mlx;
   void *mlx_win;
   t_data *img;

   img = create_image();
   mlx = mlx_init();
   img->img = mlx_new_image(mlx, 1920, 1080);
   img->addr = mlx_get_data_addr(&img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

   mlx_win = mlx_new_window(mlx, 1920, 1080, "minirt");
 /*
   mlx_key_hook
   mlx_mouse_hook */
   mlx_loop(mlx);
}