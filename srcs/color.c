/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:19:06 by user              #+#    #+#             */
/*   Updated: 2022/01/22 22:33:37 by user             ###   ########.fr       */
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

t_color c_mix(t_color *source, t_color *obj, double ratio)
{
    t_color mixed;
    mixed.r = (source->r * 0) + ((ratio * obj->r));
    mixed.g = (source->g * 0) + ((ratio * obj->g));
    mixed.b = (source->b * 0) + ((ratio * obj->b));
    return (mixed);
}

t_color c_grade(t_color *source, double alpha, t_color *color)
{
    t_color new;
    /* light side */
    new = c_mix(source, color, alpha);
    new.hex = DEC(new.r, new.g, new.b);
    return (new);
}