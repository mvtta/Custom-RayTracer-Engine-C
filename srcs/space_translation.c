/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:45:49 by user              #+#    #+#             */
/*   Updated: 2022/01/24 20:42:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_vec   world2scene(int width, int heigh, t_vec *coordinates)
{
    t_vec transform;
;
    transform.x = coordinates->x + (width / 2);
    transform.y = coordinates->y + (heigh / 2);
    transform.z = coordinates->z;

    return(transform);
}