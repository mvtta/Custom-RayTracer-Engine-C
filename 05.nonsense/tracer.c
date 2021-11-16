/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:30:57 by user              #+#    #+#             */
/*   Updated: 2021/05/18 18:42:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"

int		color_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb trace(t_ray ray, t_sphere sphere)
{
    raytosphere(&ray, sphere);
    return (ray.ray_color);
}

void    ray_tracer(t_data img, int x, int y)
{
    t_rgb       color;
	t_ray		ray;
    t_cam       cam;
    t_sphere sphere;


    ray_init(&ray);
    color_init(&color);
    set_cam_pos(&ray, cam, x, y);
    color = trace(ray, sphere);
    my_pixel_put(&img, x, y, &color);
}