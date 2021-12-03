/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:22 by user              #+#    #+#             */
/*   Updated: 2021/12/01 19:33:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_vec normalize(t_vec *p)
{
    float w = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
    p->x /= w;
    p->y /= w;
    p->z /= w;
    return (*p);
}

t_color c_blend(float alpha, t_color *color)
{
    t_color new;
    
    alpha = BLACK(alpha);
    //printf("\t PERCENTAGE alpha: %f\n", alpha);
  /*   printf("\t r: %d\n", (color->r));
    printf("\t g: %d\n", (color->g));
    printf("\t b: %d\n", (color->b));
    printf("\t BITr: %d\n", BIT(color->r));
    printf("\t BITg: %d\n", BIT(color->g)); */
   // printf("\t BITb: %d\n", BIT(color->b));
    new.r = (alpha) * BIT(color->r);
    new.g = (alpha) * BIT(color->g);
    new.b = (alpha) * BIT(color->b);
/*     printf("\t NEWS: %d\n", new.r);
    printf("\t NEWS: %d\n", new.g);
    printf("\t NEWS: %d\n", new.b); */
    new.hex = DEC(new.r, new.g, new.b);
/*     printf("\t IS IT ZERO OR WHAT MTF %u\n", new.hex); */
    return (new);
}

t_vec v_scale(float scale, t_vec *vec)
{
    t_vec new;

    new.x = vec->x *scale;
    new.y = vec->y *scale;
    new.z = vec->z *scale;

    return (new);
}

t_vec v_sub(t_vec *v1, t_vec *v2)
{
    t_vec new;

    new.x = v1->x - v2->x;
    new.y = v1->y - v2->y;
    new.z = v1->z - v2->z;

    /*     printf("**********SUBTRACTION********\n");
        printf("v1x:%f\n", v1->x);
        printf("v1y:%f\n", v1->y);
        printf("v1z:%f\n", v1->z);
        printf("v2z:%f\n", v2->z);

        printf("new_x:%f\n", new.x);
        printf("new_y:%f\n", new.y);
        printf("new_z:%f\n", new.z); */
    return (new);
}

t_vec v_add(t_vec *v1, t_vec *v2)
{
    t_vec new;

    printf("v1-> x:%f\ty:%f\tz:%f\n", v1->x, v1->y, v1->z);
    printf("v2-> x:%f\ty:%f\tz:%f\n", v2->x, v2->y, v2->z);
    //exit(0);
    new.x = v1->x + v2->x;
    new.y = v1->y + v2->y;
    new.z = v1->z + v2->z;

    return (new);
}

t_vec v_mult(t_vec *v1, t_vec *v2)
{
    t_vec new;

    new.x = v1->x * v2->x;
    new.y = v1->y * v2->y;
    new.z = v1->z * v2->z;

    return (new);
}

float dot_p(t_vec *v1, t_vec *v2)
{
    float dot;
    float a;
    float b;
    float c;

    a = v1->x * v2->x;
    b = v1->y * v2->y;
    c = v1->z * v2->z;
    /*
        printf("**********DOT**********\n");
        printf("v1x:%f\n", v1->x);
        printf("v1y:%f\n", v1->y);
        printf("v1z:%f\n", v1->z);

        printf("a:%f\n", a);
        printf("b:%f\n", b);
        printf("c:%f\n", c); */

    dot = a + b + c;
    // printf("dot:%f\n", dot);
    return (dot);
}