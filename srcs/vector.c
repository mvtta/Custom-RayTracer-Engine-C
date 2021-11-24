/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:22 by user              #+#    #+#             */
/*   Updated: 2021/11/24 17:07:31 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_vec   v_sub(t_vec *v1, t_vec *v2)
{
    t_vec new;

    new.x = v1->x - v2->x;
    new.y = v1->y - v2->y;
    new.z = v1->z - v2->z;

    printf("**********SUBTRACTION********\n");    
    printf("v1x:%f\n", v1->x);
    printf("v1y:%f\n", v1->y);
    printf("v1z:%f\n", v1->z);
    printf("v2z:%f\n", v2->z);
    
    printf("new_x:%f\n", new.x);
    printf("new_y:%f\n", new.y);
    printf("new_z:%f\n", new.z);
    return(new);
}

float  dot_p(t_vec *v1, t_vec *v2)
{
    float dot;
    float a;
    float b;
    float c;

    a = v1->x * v2->x;
    b = v1->y * v2->y;
    c = v1->z * v2->z;

    printf("**********DOT**********\n");    
    printf("v1x:%f\n", v1->x);
    printf("v1y:%f\n", v1->y);
    printf("v1z:%f\n", v1->z);
    
    printf("a:%f\n", a);
    printf("b:%f\n", b);
    printf("c:%f\n", c);

    dot = a + b + c;
    printf("dot:%f\n", dot);
    return(dot); 
}