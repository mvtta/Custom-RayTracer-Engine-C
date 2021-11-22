/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:18:03 by user              #+#    #+#             */
/*   Updated: 2021/11/22 17:53:27 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void fill_scene(t_frame *rt, char id)
{
    char *data;
    if (id == 'A')
        data = rt->ambient;
    if (id == 'C')
        data = rt->camera;
    if (id == 'L')
        data = rt->light;
    attribute(rt, rt->scene, id, data);
    return;
}

void create_scene(t_frame *rt)
{
    t_scene *scene;
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    scene = init_scene();
    rt->scene = scene;
    fill_scene(rt, 'A');
    write(1, "\nscene_created: A\n", 17);
    fill_scene(rt, 'C');
    write(1, "\nscene_created: C\n", 17);
    fill_scene(rt, 'L');
    write(1, "\nscene_created: L\n", 17);

    mlx_win = mlx_new_window(mlx, 1920, 1080, "minirt");
    mlx_loop(mlx);
    return;
}


void create_objs(t_frame *rt)
{
    t_obj *obj = rt->objs_first;
    write(1, "\n inside_create obj\n", 20);
    while(obj->next != NULL)
    {
        if(obj->raw[0] == 's')
            create_sphere(obj, obj->raw);
/*         if(obj->raw[0] == 'p')
            create_cylind();
        if(obj->raw[0] == 'c')
            create_plane(); */
        obj = obj->next;
    }
    return;
}