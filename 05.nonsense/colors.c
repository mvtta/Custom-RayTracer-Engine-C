/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:36:19 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/18 18:37:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"

/* Create an RGBf with the given values */
t_rgb new_rgb(float red, float green, float blue)
{
    t_rgb result;
    result.r = red;
    result.g = green;
    result.b = blue;
    return (result);
}

/* Scale a color by a constant float value */
t_rgb scale_rgb(t_rgb color, float value)
{
    return new_rgb(color.r * value, color.g * value, color.b * value);
}

/* Add two colors together */
t_rgb addRGB(t_rgb a, t_rgb b)
{
    return new_rgb(a.r + b.r, a.g + b.g, a.b + b.b);
}
