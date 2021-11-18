/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:06:51 by user              #+#    #+#             */
/*   Updated: 2021/11/18 13:26:31 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void att_ambient(t_frame *rt, char id, char **data)
{
    rt->scene->ambient = ascii_to_float(data[1]);
    rt->scene->light_color = ascii_to_rgb(data[2]);
    return;
}

void att_camera(t_frame *rt, char id, char **data)
{
    rt->scene->cam_coord = ascii_to_vec(data[1]);
    rt->scene->cam_norm = ascii_to_vec(data[2]);
    rt->scene->fov = ascii_to_int(data[3]);
    return;
}

void att_light(t_frame *rt, char id, char **data)
{
    rt->scene->light_coord = ascii_to_vec(data[1]);
    rt->scene->brightness = ascii_to_float(data[2]);
    return;
}

void attribute(t_frame *rt, char id, char *data)
{
    char **split_data;

    split_data = ft_split(data, ' ');
   
    if (id == 'A')
        att_ambient(rt, id, split_data);
    if (id == 'C')
        att_camera(rt, id, split_data);
    if (id == 'L')
        att_light(rt, id, split_data);
    return;
}

void fill_scene(t_frame *rt, char id)
{
    char *data;

    if (id == 'A')
        data = rt->ambient;
    if (id == 'C')
        data = rt->camera;
    if (id == 'L')
        data = rt->light;
    attribute(rt, id, data);
    return;
}