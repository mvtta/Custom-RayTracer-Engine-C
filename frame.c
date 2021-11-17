/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:35:32 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/17 20:16:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"s

t_frame *init_frame(void)
{
  t_frame *rt;
  rt = malloc(sizeof (t_frame));
  if(!rt)
    return(NULL);
  rt->scene = NULL;
  rt->objs_first = NULL;
  rt->objs_last = NULL;
  rt->nbr_objs = 0;
  return(rt);
}

t_frame *fill_frame(t_frame *rt)
{
    char *data;
    char id1;
    char id2;

    id1 = data[0];
    id2 = id2;
    while(data = parse_input())
    {
        if(id1 == 'A')
           rt->ambient = save_raw(data); 
        if(id1 == 'C')
            rt->camera = save_raw(data);
        if(id1 == 'L')
            rt->light = save_raw(data);
        if(id1 == 's' && id2 == 'p')
            add_new_obj(rt, data);
        if(id1 == 'p' && id2 == 'l')
            add_new_obj(rt, data);
        if(id1 == 'c' && id2 == 'y')
            add_new_obj(rt, data);
        free(data);
    }
    retunr(rt);
}

t_frame *kill_frame(t_frame *rt)
{
    free(rt->ambient);
    free(rt->camera);
    free(rt->light);
    rt->ambient = NULL;
    rt->camera = NULL;
    rt->light = NULL;

   return(rt);
}   