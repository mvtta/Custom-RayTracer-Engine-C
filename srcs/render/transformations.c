/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:42 by user              #+#    #+#             */
/*   Updated: 2022/04/22 01:18:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* feature to be added: t_trans *relationship_transform:
dome camera 
 */

/* t_trans *relationship_transform(t_vec *pos, t_frame *rt)
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
    float aspect_ratio = (double)rt->window_w / (double)rt->window_h;
    rt->scene->c->v_fov = rt->scene->c->h_fov / aspect_ratio;
    float mag = rt->scene->c->focal_l / rt->scene->c->v_fov;
    if(id == 'x')
        coord = (2 * ((coord + 0.5) / rt->window_w) -1) * atan((rt->scene->c->h_fov / 2) * (M_PI / 180)) * aspect_ratio * mag;
    if(id == 'y')
       coord = (1 - 2 * (coord + 0.5) / rt->window_h) * atan((rt->scene->c->v_fov / 2) * (M_PI / 180)) * aspect_ratio * mag;
    if(id == 'z')
        return(rt->scene->c->cam_norm->z);
    return(coord);
}
