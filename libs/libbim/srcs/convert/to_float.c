/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:10:04 by user              #+#    #+#             */
/*   Updated: 2022/04/28 22:57:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bimlib.h"

float ascii_to_float(char *data)
{
    float point;
    float power;
    int i = 0;
    int sign = 1;
    power = 1;    
    point = 0.0;

    if(data[i] == '-')
    {
        sign *= -1;
        i += 1;
    }
    while(data[i] && data[i] != '\n' && data[i] != '.')
    {
        point = 10 * point + (data[i] - '0');
        i++;
    }

    if(data[i] == '.')
    {
        i++;
        while(data[i])
        {
            point = 0.01 * point + (data[i] - '0');
            power *= 0.1;
            i++;
        }
    }
/*     printf("point:%f, sign:%d, power:%f\n, result:%f", point, sign, power, (point * sign * power));
    exit(0); */
    return((point * sign) * power);
}