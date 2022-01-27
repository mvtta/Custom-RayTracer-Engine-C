/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:30:11 by user              #+#    #+#             */
/*   Updated: 2022/01/27 13:25:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float get_time_pl(t_ray *ray, t_vec *point, t_vec *normal)
{
    float time;
    float numerator;
    float denom;
    t_vec to_point;

    to_point = v_sub(&ray->start, point);
    to_point = normalize(&to_point);
    numerator = dot_p(&to_point, normal);
    denom = dot_p(&ray->dir, normal);
    if(denom > 1e-3)
    {
        time = (numerator / denom) * -1.0;
        if(time > 1e-3 && time < 1)
            return(time * 10);
    }
    return(NO_HIT);
}