/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:36:19 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/14 22:43:57 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"

/* Create an RGBf with the given values */
t_rgbf new_rgb(float red, float green, float blue)
{
    t_rgbf result;
    result.r = red;
    result.g = green;
    result.b = blue;
    return (result);
}

/* Scale a color by a constant float value */
t_rgbf scale_rgb(t_rgbf color, float value)
{
    return new_rgb(color.r * value, color.g * value, color.b * value);
}

/* Add two colors together */
t_rgbf addRGB(t_rgbf a, t_rgbf b)
{
    return new_rgb(a.r + b.r, a.g + b.g, a.b + b.b);
}
