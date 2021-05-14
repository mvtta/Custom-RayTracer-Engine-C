/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:20:41 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/14 21:31:16 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"

/* Create a new Vector with the given values */
t_vec new_v(float x, float y, float z)
{
    t_vec result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

/* Compute the magnitude of a t_ray */
float mag(t_vec v)
{
    return (sqrt(v.x*v.x + v.y*v.y + v.z*v.z));
}

/* Compute the dot product of two vectors */
float dot(t_vec a, t_vec b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/* Scale a t_vec by a constant value */
t_vec scale_v(float value, t_vec v)
{
    return (new_v(v.x * value, v.y * value, v.z * value));
}

/* Compute the cross-product of two vectors */
t_vec cross(t_vec a, t_vec b)
{
    return (new_v(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x));
}

/* Compute the addition of two vectors */
t_vec add_v(t_vec a, t_vec b)
{
    return (new_v(a.x + b.x, a.y + b.y, a.z + b.z));
}

/* Compute a vector produced by substracting a vector from another */
t_vec minus_v(t_vec a, t_vec b)
{
    return (add_v(a, scale_v(-1,b)));
}