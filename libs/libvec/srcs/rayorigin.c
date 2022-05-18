/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayorigin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:34:44 by user              #+#    #+#             */
/*   Updated: 2022/05/02 14:34:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec *ro_3(t_ray *ray, t_vec *where)
{
    ray->start->x = where->x;
    ray->start->y = where->y;
    ray->start->z = where->z;
    return(ray->start);
}