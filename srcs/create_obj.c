/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:20 by user              #+#    #+#             */
/*   Updated: 2022/01/27 05:38:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_obj *new_obj(t_frame *rt, char *data)
{
    t_obj *new = NULL;

    new = malloc(sizeof(t_obj));
    printf("data in <data> new obj: %s\n", data);
     /* parse raw_data_now */
    new->raw = malloc(ft_strlen(data) + 1);
    ft_strlcpy(new->raw, data, ft_strlen(data));
    printf("data in <raw> new obj: %s\n", new->raw);
    new->prev = NULL;
    new->next = NULL;
    new->id1 = new->raw[0];
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
    t_obj *new = NULL;
    t_obj *old_tail = NULL;
    char *input = NULL;


    input = malloc(ft_strlen(data) + 1);
    ft_strlcpy(input, data, ft_strlen(data) + 1);
    new = new_obj(rt, input);
    free(input);
    
    if(rt->objs_first == NULL)
    {
        rt->objs_first = new;
        rt->objs_last = new;
        rt->objs_first->prev = NULL;
        rt->objs_first->next = rt->objs_last;
        rt->objs_last->prev = rt->objs_first;
        return;
    }

    old_tail = rt->objs_last;
    new->prev = old_tail;
    new->next = NULL;
    old_tail->next = new;
    old_tail->prev = old_tail->prev->next;
    rt->objs_last = new;
    rt->objs_last->prev = new->prev;
    return;
}

void create_plane(t_obj *obj, char *data)
{
    char **plane;
    static int count;
    plane = ft_split(data, ' ');

    /* pl 0,100,0 0,0,1 255,255,255; */
    obj->id1 = 'p';
    obj->id2 = count;
    obj->obj_coord = ascii_to_vec(plane[1]);
    obj->obj_norm = ascii_to_vec(plane[2]);
    printf("x:%f\n", obj->obj_coord->x);
    printf("y:%f\n", obj->obj_coord->y);
    printf("z:%f\n", obj->obj_coord->z);
    printf("\trgb data[3]:%s\n", plane[3]);
    obj->obj_color = ascii_to_rgb(plane[3]);
    printf("r:%d\n", obj->obj_color->r);
    printf("g:%d\n", obj->obj_color->g);
    printf("b:%d\n", obj->obj_color->b);
    count += 1;
    
}

void create_sphere(t_obj *obj, char *data)
{
    char **sphere;
    static int count;
    sphere = ft_split(data, ' ');

    obj->id1 = 's';
    obj->id2 = count;
    obj->obj_coord = ascii_to_vec(sphere[1]);
    printf("x:%f\n", obj->obj_coord->x);
    printf("y:%f\n", obj->obj_coord->y);
    printf("z:%f\n", obj->obj_coord->z);
    obj->diameter = ascii_to_float(sphere[2]);
    obj->obj_color = ascii_to_rgb(sphere[3]);
    count += 1;
}

void create_cylin(t_obj *obj, char *data)
{
    char **cylin;
    static int count;
    cylin = ft_split(data, ' ');

    obj->id1 = 'c';
    obj->id2 = count;
    obj->obj_coord = ascii_to_vec(cylin[1]);
    obj->obj_norm = ascii_to_vec(cylin[2]);
    printf("x:%f\n", obj->obj_coord->x);
    printf("y:%f\n", obj->obj_coord->y);
    printf("z:%f\n", obj->obj_coord->z);
    obj->diameter = ascii_to_float(cylin[3]);
    obj->height = ascii_to_float(cylin[4]);
    obj->obj_color = ascii_to_rgb(cylin[5]);
    count += 1;
}

