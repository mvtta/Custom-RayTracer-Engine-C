/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:18:03 by user              #+#    #+#             */
/*   Updated: 2021/11/18 13:24:09 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void create_scene(t_frame *rt)
{
    fill_scene(rt, 'A');
    fill_scene(rt, 'C');
    fill_scene(rt, 'L');
    return;
}


void create_objs(t_frame *rt)
{
    t_obj *obj = rt->objs_first;
    
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