/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:18:03 by user              #+#    #+#             */
/*   Updated: 2021/12/03 11:15:40 by user             ###   ########.fr       */
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
create_sphere(rt->objs_first, rt->objs_first->raw);
    return;
}