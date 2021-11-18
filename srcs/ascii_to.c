/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:59:20 by user              #+#    #+#             */
/*   Updated: 2021/11/18 13:23:48 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int ascii_to_int(char *data)
{
    int i;
    int sign = 0;
    int nbr = 0;

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

unsigned int *ascii_to_hex(int r, int g, int b)
{
    unsigned int *hex;

    hex = ((r & 0xff) << 24) + ((g & 0xff) << 16 ) + ((b & 0xff) << 8);
    return(hex);
} 

t_color *ascii_to_rgb(char *data)
{
    char **colors;

    t_color *color_in_hex;

    color_in_hex = (malloc(sizeof(t_color)));
    colors = ft_split(data, ',');

    color_in_hex->r = ascii_to_int(&data[0]);
    color_in_hex->g = ascii_to_int(&data[1]);
    color_in_hex->b = ascii_to_int(&data[2]);
    color_in_hex->hex = ascii_to_hex(color_in_hex->r, color_in_hex->g, color_in_hex->b);

}