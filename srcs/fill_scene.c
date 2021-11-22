/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:06:51 by user              #+#    #+#             */
/*   Updated: 2021/11/22 14:22:36 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_scene *att_ambient(t_scene *scene, char **data)
{
    scene->ambient = ascii_to_float(data[1]);
    scene->light_color = ascii_to_rgb(data[2]);
    return(scene);
}

t_scene *att_camera(t_scene *scene, char **data)
{
/*     write(1, "\ncam_coord\n", 11);
    write(1, data[1], ft_strlen(data[1]));
    write(1, "\ncam_norm\n", 10);
    write(1, data[2], ft_strlen(data[2]));
    write(1, "\nfov\n", 5);
    write(1, data[2], ft_strlen(data[3])); */
    scene->cam_coord = ascii_to_vec(data[1]);
    scene->cam_norm = ascii_to_vec(data[2]);
    scene->fov = ascii_to_int(data[3]);
    return(scene);
}

t_scene *att_light(t_scene *scene,char **data)
{
    scene->light_coord = ascii_to_vec(data[1]);
    scene->brightness = ascii_to_float(data[2]);
    return(scene);
}

t_frame *attribute(t_frame *rt, t_scene *scene, char id, char *data)
{
    char **split_data;

    split_data = ft_split(data, ' ');

    if (id == 'A')
        rt->scene = att_ambient(scene, split_data);
    if (id == 'C')
        rt->scene = att_camera(scene, split_data);
    if (id == 'L')
        rt->scene = att_light(scene, split_data);
    return(rt);
}
