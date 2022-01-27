/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:18:03 by user              #+#    #+#             */
/*   Updated: 2022/01/27 05:40:44 by user             ###   ########.fr       */
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

    scene = init_scene();
    rt->scene = scene;
    fill_scene(rt, 'A');
    write(1, "\nscene_created: A\n", 17);
    fill_scene(rt, 'C');
    write(1, "\nscene_created: C\n", 17);
    fill_scene(rt, 'L');
    write(1, "\nscene_created: L\n", 17);
    return;
}

void create_objs(t_frame *rt)
{
    int i = 0;
    t_obj *current;
    current = rt->objs_first;
    while (++i <= rt->nbr_objs)
    {
        if (current->id1 == SPHERE)
            create_sphere(current, current->raw);
        if (current->id1 == PLANE)
            create_plane(current, current->raw);
        if (current->id1 == 'c')
            create_cylin(current, current->raw);
        current = current->next;
    }
    return;
}