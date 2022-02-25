/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:45:34 by user              #+#    #+#             */
/*   Updated: 2022/02/24 15:02:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float gaussian_blur();

float get_focal_len(float fov)
{
    float fl;
    float half = fov / 2;
    fl = (half / (atanf(half)));
    return((fl * 2));
}

/* void  out_of_focus(t_ray *prime)
{
    prime->dir = sin;
} */