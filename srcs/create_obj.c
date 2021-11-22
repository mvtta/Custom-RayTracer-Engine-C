/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:20 by user              #+#    #+#             */
/*   Updated: 2021/11/22 14:49:21 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_obj *new_obj(t_frame *rt, char *data)
{
    t_obj *new = NULL;

    new = malloc(sizeof(t_obj));
    new->raw = malloc(ft_strlen(data));
    new->raw = data;
     /* parse raw_data_now */
    new->prev = NULL;
    new->next = NULL;
    new->obj_coord = NULL;
    new->obj_color = NULL;
    new->obj_norm = NULL;
    new->diameter = 0;
    new->height = 0;
    rt->nbr_objs++;
    return (new);
}

void add_new_obj(t_frame *rt, char *data)
{
    t_obj *old_last = NULL;
    t_obj *new = NULL;

    new = new_obj(rt, data);
    if(rt->objs_first == NULL)
    {
        rt->objs_first = new;
        rt->objs_last = new;
        return;
    }
    old_last = rt->objs_last;
    new->prev = old_last;
    rt->objs_last = NULL;
    rt->objs_last = new;
    return;
}

void create_sphere(t_obj *obj, char *data)
{
    char **sphere;
    sphere = ft_split(data, ' ');

    write(1, "\nin create_sp\n", 14);
    obj->id1 = 's';
    obj->id2 = 'p';
    obj->obj_coord = ascii_to_vec(*ft_split(sphere[1], ','));
    obj->diameter = ascii_to_float(sphere[2]);
    obj->obj_color = ascii_to_rgb(*ft_split(sphere[3], ','));
    
}


/* void create_cylin(t_frame *rt, char *data)
{
    char **cylin;
    cylin = ft_split(data, ' ');
}
void create_plane(t_frame *rt)
{

} */
