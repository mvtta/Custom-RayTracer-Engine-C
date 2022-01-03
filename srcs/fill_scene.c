/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:06:51 by user              #+#    #+#             */
/*   Updated: 2022/01/02 22:51:41 by user             ###   ########.fr       */
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
    scene->cam_coord = ascii_to_vec(data[1]);
    scene->cam_norm = ascii_to_vec(data[2]);
    scene->fov = 50;
/*     printf("fov parsed: %f\n", scene->fov);
    printf("data0:%s\n", data[0]);
    printf("data1:%s\n", data[1]);
    printf("data2:%s\n", data[2]);
    printf("data3:%s\n", data[3]);
    exit(0); */
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
    
    printf("input on att:%s\n", data);
    printf("id on att:%c\n", id);
    split_data = ft_split(data, ' ');
    printf("split1 on att:%s\n", split_data[0]);
    printf("split2 on att:%s\n", split_data[1]);

    if (id == 'A')
        rt->scene = att_ambient(scene, split_data);
    if (id == 'C')
        rt->scene = att_camera(scene, split_data);
    if (id == 'L')
        rt->scene = att_light(scene, split_data);
    return(rt);
}
