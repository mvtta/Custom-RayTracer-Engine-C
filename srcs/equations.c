/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:30:11 by user              #+#    #+#             */
/*   Updated: 2022/02/14 02:55:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float get_time_pl(t_ray *ray, t_vec *point, t_vec *normal)
{
    float time;
    float denom;
    t_vec n = normalize(normal);
    float len = length(*ray->dir);
    t_vec d = normalize(ray->dir);
    denom = dot_p(&n, &d);

    //printf("denom%f\n", denom);
    if (denom > 0.01)
    {
        t_vec hit = v_sub(ray->start, point);
        hit = normalize(&hit);
        time = dot_p(&hit, &n) + len / denom;
 /*        printf("time%f\n", time);
        printf("len%f\n", len); */
    if (time > 0)
    {
        //printf("time%f\n", time);
        return(time);
    }
    }
    return (NO_HIT);
}
