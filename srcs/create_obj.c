/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:20 by user              #+#    #+#             */
/*   Updated: 2021/12/03 12:09:06 by user             ###   ########.fr       */
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

void create_sphere(t_obj *obj, char *data)
{
    char **sphere;
    static int count;
    sphere = ft_split(data, ' ');

    obj->id1 = SPHERE;
    obj->id2 = count;
    obj->obj_coord = ascii_to_vec(sphere[1]);
    obj->diameter = ascii_to_float(sphere[2]);
    obj->obj_color = ascii_to_rgb(sphere[3]);
    count += 1;
}

/* void create_cylin(t_frame *rt, char *data)
{
    char **cylin;
    cylin = ft_split(data, ' ');
}
void create_plane(t_frame *rt)
{

} */
