/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:42 by user              #+#    #+#             */
/*   Updated: 2022/02/03 17:42:00 by user             ###   ########.fr       */
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
    float aspect_ratio = (double)rt->window_w / (double)rt->window_h;
    float vertical_fov = rt->scene->fov / aspect_ratio;
    //float focal_len = atan(rt->scene->fov);
/*     float near_clip = 0.1;
    float far_clip = 100.0; */
/*     printf("w:%d\n", rt->window_w );
    printf("h:%d\n", rt->window_h );
    printf("asps:%f\n", aspect_ratio);
    printf("vertical_fov:%f\n", vertical_fov);
    printf("h_fov:%f\n", rt->scene->fov);
    printf("focal_len:%f\n", focal_len); */
    //exit(0);
    //float mag = rt->scene->fov;
    rt->scene->far = 1000; 
/*     printf("tanfov: %f\n, hfov %f\n vfov: %f\n mag:%f\n ar:%f\n",tan(rt->scene->fov), rt->scene->fov, vertical_fov, mag, aspect_ratio);
    printf("taanfov / 2: %f\n, ahfov / 2 %f\n",atan(rt->scene->fov), atan(vertical_fov));
    printf("tanfov / 2: %f\n, hfov / 2 %f\n",tan(rt->scene->fov / 2), tan(vertical_fov / 2));
    exit(0); */
    if(id == 'x')
        coord = (2 * ((coord + 0.5) / rt->window_w) -1) * atan((rt->scene->fov * (M_PI / 180)));
    if(id == 'y')
       coord = (1 - 2 * (coord + 0.5) / rt->window_h) * atan((vertical_fov) * (M_PI / 180));
    if(id == 'z')
        return(coord);
    return(coord);
}

/* t_vec ray(t_vec coord1, t_vec coord2)
{
    
} */