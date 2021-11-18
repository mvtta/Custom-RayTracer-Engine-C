/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:59:20 by user              #+#    #+#             */
/*   Updated: 2021/11/18 23:23:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int ascii_to_int(char *data)
{
    int i;
    int sign = 0;
    int nbr;

    i = -1;
    if(data[0] == '-')
    {
        sign += 1;
        i+=1;
    }
    while(data[i])
    {
        nbr = data[i] - 48 + nbr;
        nbr *= 10;
        i++;
    }
    return (nbr *= sign);
}

float ascii_to_float(char *data)
{
    float point;
    int nbr;

    nbr = ascii_to_int(data);
    point = (float)nbr/10;
    write(1, "\n", 1);
    write(1, data, ft_strlen(data));
    printf("\n%f\n", point);
    printf("\n%i\n", nbr);
    exit(0);
    return(point);
}

t_vec *ascii_to_vec(char *data)
{
    t_vec *vec;

    vec = malloc(sizeof(t_vec));
    char **vectorial;

    vectorial = ft_split(data, ',');
    vec->x = ascii_to_float(&data[0]);
    vec->y = ascii_to_float(&data[1]);
    vec->z = ascii_to_float(&data[2]);
    //free(vectorial);
    return(vec);
}

unsigned int ascii_to_hex(int r, int g, int b)
{
    unsigned int hex;

    hex = ((r & 0xff) << 24) + ((g & 0xff) << 16 ) + ((b & 0xff) << 8);
    return(hex);
} 

t_color *ascii_to_rgb(char *data)
{
    char **colors;

    t_color *color_in_hex;

    color_in_hex = malloc(sizeof(t_color));
     write(1, "\nhere\n", 5);
    colors = ft_split(data, ',');
    write(1, "\nhere\n", 5);
    write(1, colors[0], ft_strlen(colors[0]));
    write(1, "\n", 1);
    write(1, colors[1], ft_strlen(colors[1]));
    write(1, "\n", 1);
    write(1, colors[2], ft_strlen(colors[2]));
    write(1, "\n", 1);

    color_in_hex->r = ascii_to_int(colors[0]);
    color_in_hex->g = ascii_to_int(colors[1]);
    color_in_hex->b = ascii_to_int(colors[2]);
    color_in_hex->hex = ascii_to_hex(color_in_hex->r, color_in_hex->g, color_in_hex->b);

    return(color_in_hex);
}