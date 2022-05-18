/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_mag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:36:05 by user              #+#    #+#             */
/*   Updated: 2022/05/02 14:36:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

float v_mag(t_vec *v1, t_vec *v2)
{
    float x = (v2->x - v1->x) * (v2->x - v1->x);
    float y = (v2->y - v1->y) * (v2->y - v1->y);
    float z = (v2->z - v1->z) * (v2->z - v1->z);
    float magnitude = sqrtf(x + y + z);
    return (magnitude);
}