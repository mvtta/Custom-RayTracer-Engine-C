/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:19:06 by user              #+#    #+#             */
/*   Updated: 2022/01/26 16:56:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* declaring black */
const t_color black = {0, 0, 0, 0};
const t_color yellow = {255, 255, 0, 0};
/* declaring primaries */
const t_color red = {1, 0, 0, 0};
const t_color green = {0, 1, 0, 0};
const t_color blue = {0, 0, 1, 0};
const int rgb[3] = {1, 2, 3};

int c_increase(int max)
{
    if (max > L)
        return (max - L);
    return (0);
}

float c_percentage(int color)
{
    return (color / 255);
}

int c_hue(t_color *check)
{
    float c[3];
    int index = 0;
    int highest = 0;

    c[0] = c_percentage(check->r);
    c[1] = c_percentage(check->g);
    c[2] = c_percentage(check->b);

    highest = 0;
    while (c[index])
    {
        if (highest < c[index])
            highest = c[index];
        index++;
    }
    return (index);
}

t_color c_mix(t_color *source, t_color *obj, double spec, double difuse)
{
    t_color mixed;
/*     printf("spec%f\n", spec);
    printf("source%d\n", source->b); */
    mixed.r = (source->r * spec) + (obj->r * difuse);
    mixed.g = (source->g * spec) + (obj->g * difuse);
    mixed.b = (source->b * spec) + (obj->b * difuse);
    return (mixed);
}

t_color c_grade(t_color *source, t_color *color, double spec, double difuse)
{
    t_color new;
    /* light side */
    new = c_mix(source, color, spec, difuse);
    new.hex = DEC(new.r, new.g, new.b);
    return (new);
}