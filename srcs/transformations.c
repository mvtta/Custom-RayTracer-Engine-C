/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:42 by user              #+#    #+#             */
/*   Updated: 2021/12/22 21:39:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* t_trans *relationashiop_transform(t_vec *pos, t_frame *rt)
{
    t_trans *ret;
    
    ret->cam_matrix.p_x = rt->window_w / 2;
    ret->cam_matrix.p_y = rt->window_h / 2;
    ret->cam_matrix.n_x = (rt->window_w / 2) * -1;
    ret->cam_matrix.n_y = (rt->window_h / 2) * -1;

    ret->cam_in_3dworld = pos;
    ret->anything_to_screen = 
} */

float  ndc(t_frame *rt, float coord, char id)
{
    float aspect_ratio = rt->window_w / rt->window_h;
    if(id == 'x')
        coord = (2 * ((coord + 0.5) / rt->window_w) -1) * tan(rt->scene->fov / 2 * M_PI / 360) * aspect_ratio * 0.5;
    if(id == 'y')
       coord = (1 - 2 * (coord + 0.5) / rt->window_h) * tan(rt->scene->fov / 2 * M_PI / 360) * 0.5;
    if(id == 'z')
        coord = 1;
    return(coord);
}