/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:59:20 by user              #+#    #+#             */
/*   Updated: 2021/11/29 18:57:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int ascii_to_int(char *data)
{
    int i;
    int sign = 1;
    int nbr = 0;

    i = -1;
    if (data[0] == '-')
    {
        sign = -1;
        i += 1;
    }
    if(data[0] == '0')
        return(0);
    while (data[++i])
        nbr = data[i] - 48 + nbr * 10;
    return (nbr *= sign);
}

float ascii_to_float(char *data)
{
    float point;
    int power;
    int i = 0;
    int sign = 1;
    power = 1.0;    
    point = 0.0;

    if(data[0] == '-')
        sign = -1;
    while(data[i] && data[i] != '.')
    {
        point = 10.0 * point + (data[i] - '0');
        i++;
    }

    if(data[i] == '.')
    {
        i++;
        while(data[i])
        {
            point = 10.0 * point + (data[i] - '0');
            power *= 10.0;
            i++;
        }
    }
    return(sign * point / power);
   // point = ((float)nbr);
    /*     printf("\n%d\n", nbr);
    printf("\n%d\n", i);
    printf("\n%f\n", point);
    exit(0); */
    printf("float out:%f\n", point);
    return (point);
}

t_vec *ascii_to_vec(char *data)
{
    t_vec *vec = NULL;

    vec = malloc(sizeof(t_vec));
    char **vectorial;

    vectorial = ft_split(data, ',');
    
 /*    printf("vectx%s\n", vectorial[0]);
    printf("vecy%s\n", vectorial[1]);
    printf("vecz%s\n", vectorial[2]); */
    
    vec->x = ascii_to_float(vectorial[0]);
    vec->y = ascii_to_float(vectorial[1]);
    vec->z = ascii_to_float(vectorial[2]);
    //free(vectorial);
    return (vec);
}


unsigned int ascii_to_hex(int r, int g, int b)
{
    uint32_t hex;
  
    hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff));
    return (hex);
}

t_color *ascii_to_rgb(char *data)
{
    char **colors;
    t_color *color_in_hex;
    color_in_hex = malloc(sizeof(t_color));
    
    colors = ft_split(data, ',');

    printf("data0:%s\n", colors[0]);
    printf("data1:%s\n", colors[1]);
    printf("data2:%s\n", colors[2]);
    //exit(0);

    color_in_hex->r = ascii_to_int(colors[0]);
    color_in_hex->g = ascii_to_int(colors[1]);
    color_in_hex->b = ascii_to_int(colors[2]);
    color_in_hex->hex = ascii_to_hex(color_in_hex->r, color_in_hex->g, color_in_hex->b);
    return (color_in_hex);
}