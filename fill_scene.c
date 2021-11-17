/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:06:51 by user              #+#    #+#             */
/*   Updated: 2021/11/17 20:17:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void att_ambient(t_frame *rt, char id, char **data)
{
    rt->scene->ambient = ascii_float(data[1]);
    rt->scene->light_color = ascii_rgb(data[2]);
    return;
}

void att_camera(t_frame *rt, char id, char **data)
{
    rt->scene->cam_coord = ascii_vec(data[1]);
    rt->scene->cam_norm = ascii_vec(data[2]);
    rt->scene->fov = ascii_int(data[3]);
    return;
}

void att_light(t_frame *rt, char id, char **data)
{
    rt->scene->light_coord = ascii_vec(data[1]);
    rt->scene->brightness = ascii_float(data[2]);
    rt->scene->brightness = ascii_rgb(data[3]);
    return;
}

void attribute(t_frame *rt, char id, char *data)
{
    char **split_data;

    split_data = ft_split(data, ' ');
   
    if (id = 'A')
        att_ambiet(rt, id, split_data);
    if (id = 'C')
        att_ambiet(rt, id, split_data);
    if (id = 'L')
        att_ambiet(rt, id, split_data);
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