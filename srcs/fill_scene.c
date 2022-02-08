/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:06:51 by user              #+#    #+#             */
/*   Updated: 2022/02/05 22:02:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void att_ambient(t_frame *rt, char **data)
{
    rt->scene->a->ambient = ascii_to_float(data[1]);
    rt->scene->a->amb_color = ascii_to_rgb(data[2]);
    return;
}

void att_camera(t_frame *rt, char **data)
{
    rt->scene->c->cam_coord = ascii_to_vec(data[1]);
    rt->scene->c->cam_norm = ascii_to_vec(data[2]);
    rt->scene->c->h_fov = ascii_to_float(data[3]);
    return;
}

void att_light(t_frame *rt, char **data)
{
    rt->scene->l->light_coord = ascii_to_vec(data[1]);
    rt->scene->l->brightness = ascii_to_float(data[2]);
    rt->scene->l->light_color = ascii_to_rgb(data[3]);
    return;
}

t_frame *attribute(t_frame *rt, char id, char *data)
{
    char **split_data;

    split_data = ft_split(data, ' ');

    if (id == 'A')
        att_ambient(rt, split_data);
    if (id == 'C')
        att_camera(rt, split_data);
    if (id == 'L')
        att_light(rt, split_data);
    return (rt);
}
