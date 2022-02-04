/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:02:38 by user              #+#    #+#             */
/*   Updated: 2022/01/24 20:16:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_ray ray_from_to(t_vec *point_origin, t_vec *point_direction)
{
    t_ray new;
    new.start = *point_origin;
    new.dir = v_sub(point_origin, point_direction);
    new.len = length(new.dir);
    new.norm = normalize(&new.dir);
    return(new);
}

/* t_vec ray_time(t_vec point_origin, t_vec point_direction)
{

}

t_vec ray_invert_direction(t_vec point_origin, t_vec point_direction)
{

} */