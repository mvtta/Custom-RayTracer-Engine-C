/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:30:11 by user              #+#    #+#             */
/*   Updated: 2022/02/01 21:12:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float get_time_pl(t_ray *ray, t_vec *point, t_vec *normal)
{
    float time;
    float numerator;
    float denom;
    t_vec to_point;

    to_point = v_sub(point, &ray->start);
    to_point = normalize(&to_point);
    numerator = dot_p(&to_point, normal);
    denom = dot_p(&ray->dir, normal);
    // printf("denom:%f\n", denom);
    if (denom > 0.001)
    {
        time = (numerator / denom);
        // printf("time:%f\n", time);
        if (time > 1e-4)
        {
            float top = point->y * -normal->y;
            float bot = point->z * normal->z;
            float rd = ray->start.y + (time * to_point.y);
/*             printf("rd:%f\n", rd);
            printf("top:%f\n", top);
            printf("bot:%f\n", bot); */
            if ((rd >= bot) && (rd <= top))
            {
/*                 printf("rd:%f\n", rd);
                printf("top:%f\n", top);
                printf("bot:%f\n", bot); */
                //printf("rd:%f\n", rd);
                return (time * 10);
            }
        }
    }
    return (NO_HIT);
}
