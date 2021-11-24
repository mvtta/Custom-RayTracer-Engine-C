/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:20 by user              #+#    #+#             */
/*   Updated: 2021/11/24 16:46:50 by mvaldeta         ###   ########.fr       */
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

/*     printf("obj 0:%s\n", sphere[0]);
    printf("obj 1:%s\n", sphere[1]);
    printf("obj 2:%s\n", sphere[2]);
    printf("obj 3:%s\n", sphere[3]); */

    obj->id1 = 's';
    obj->id2 = 'p';
    obj->obj_coord = ascii_to_vec(sphere[1]);
    obj->diameter = ascii_to_float(sphere[2]);
    obj->obj_color = ascii_to_rgb(sphere[3]);

/*     printf("objx:%f\n", obj->obj_coord->x);
    printf("objy:%f\n", obj->obj_coord->y);
    printf("objz:%f\n", obj->obj_coord->z);
    printf("objdiameter:%f\n", obj->diameter); */
    //exit(0);
}


/* void create_cylin(t_frame *rt, char *data)
{
    char **cylin;
    cylin = ft_split(data, ' ');
}
void create_plane(t_frame *rt)
{

} */
