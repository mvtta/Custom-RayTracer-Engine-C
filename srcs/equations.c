/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:30:11 by user              #+#    #+#             */
/*   Updated: 2022/02/11 04:36:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float get_time_pl(t_ray *ray, t_vec *point, t_vec *normal)
{
    float time;
    float denom;
    denom = dot_p(normal, ray->dir);
    //printf("denom%f\n", denom);
    if (denom > 0.01)
    {
        t_vec hit = v_sub(ray->start, point);
        time = dot_p(&hit, normal)  / denom;
        //printf("time%f\n", time);
    if (time > 0.01 && time < (ray->start->z + 100))
    {
        //printf("time%f\n", time);
        return(time);
    }
    }
    return (NO_HIT);
}
