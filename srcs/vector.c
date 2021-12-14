/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:22 by user              #+#    #+#             */
/*   Updated: 2021/12/13 15:56:58 by user             ###   ########.fr       */
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

t_color c_mix(float volume, float light, t_color *obj_color)
{
    t_color model;
    t_color shaded;

    model = c_blend(volume, obj_color);
    shaded = c_luminance(light, &model);
    return(shaded);
}

t_color c_blend(float alpha, t_color *color)
{
    t_color new;
    
    alpha = BLACK(alpha);
    new.r = (alpha) * BIT(color->r);
    new.g = (alpha) * BIT(color->g);
    new.b = (alpha) * BIT(color->b);

    new.hex = DEC(new.r, new.g, new.b);
    return (new);
}

t_color c_luminance(float alpha, t_color *color)
{
    t_color final;

    //printf("ALPHA: %f\n", alpha);
    //printf("ALPHA QUANTIY: %f\n", (PL(alpha)));

/*     if(alpha == 0)
        alpha = 0.2;
 */
    alpha = PL(alpha);
    final.r = (alpha) * color->r + color->r;
    final.g = (alpha) * color->g + color->g;
    final.b = (alpha) * color->b + color->b;

/*     printf("color R: %u\n", color->r);
    printf("color G: %u\n", color->g);
    printf("color B: %u\n", color->b);

    printf("FINAL R: %u\n", final.r);
    printf("FINAL G: %u\n", final.g);
    printf("FINAL B: %u\n", final.b); */

    final.hex = DEC(AVOID_MAX(final.r), AVOID_MAX(final.g), AVOID_MAX(final.b));
    return (final);
}

t_vec v_scale(float scale, t_vec *vec)
{
    t_vec new;

    new.x = vec->x *scale;
    new.y = vec->y *scale;
    new.z = vec->z *scale;

    return (new);
}

float v_mag(t_vec *v1, t_vec *v2)
{
    float x = (v2->x - v1->x) * (v2->x - v1->x);
    float y = (v2->y - v1->y) * (v2->y - v1->y);
    float z = (v2->z - v1->z) * (v2->z - v1->z);
    float magnitude = sqrtf(x + y + z);
    return(magnitude);
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