/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:35:32 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/18 19:08:55 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_frame *init_frame(void)
{
    t_frame *rt;
    rt = malloc(sizeof(t_frame));
    if (!rt)
        return (NULL);
    rt->scene = NULL;
    rt->objs_first = NULL;
    rt->objs_last = NULL;
    rt->nbr_objs = 0;
    printf("frame initialized\n");
    return (rt);
}

t_frame *fill_frame(t_frame *rt)
{
    char *data;
    char id1;
    char id2;
    int fd;

    printf("preparing to fill\n");
    fd = open("scene_test.rt", O_RDONLY);
    printf("file opened, fd:%d\n", fd);
    data = get_next_line(fd);
    printf("data: %s\n", data);
    while ((data))
    {   
        write(1, "OLA\n", 4);
        printf("data: %s\n", data);
        id1 = data[0];
        id2 = data[1];
        printf("id1:%c \t id2:%c\n", id1, id2);
        if (id1 == 'A')
            rt->ambient = save_raw(data);
        if (id1 == 'C')
            rt->camera = save_raw(data);
        if (id1 == 'L'|| id2 == 'L')
            rt->light = save_raw(data);
        if (id1 == 's' && id2 == 'p')
            add_new_obj(rt, data);
        if (id1 == 'p' && id2 == 'l')
            add_new_obj(rt, data);
        if (id1 == 'c' && id2 == 'y')
            add_new_obj(rt, data);
        free(data);
        data = get_next_line(fd);
    }
    printf("frame filled\n");
    return (rt);
}

t_frame *kill_frame(t_frame *rt)
{
    free(rt->ambient);
    free(rt->camera);
    free(rt->light);
    rt->ambient = NULL;
    rt->camera = NULL;
    rt->light = NULL;

    return (rt);
}