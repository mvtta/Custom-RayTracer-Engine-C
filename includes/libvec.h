/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:41:29 by user              #+#    #+#             */
/*   Updated: 2022/05/17 09:47:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <float.h>


/* Data Structs */

typedef struct s_point
{
    float x;
    float y;
    float z;
} t_point;

typedef struct s_vec
{
    float x;
    float y;
    float z;
} t_vec;

typedef struct s_ray
{
    t_vec *start;
    t_vec *dir;
    t_vec *norm;
    float len;
} t_ray;

/* vector.c */
float       degree_to_percentage(float degree);
float       v_mag(t_vec *v1, t_vec *v2);
float       dot_p(t_vec *v1, t_vec *v2);
double		length_squared(t_vec v);
double      angle_bet_vs(t_vec *v1, t_vec *v2);
double		length(t_vec v);
double      sqr(double n);
t_vec       normal_2p(t_vec *p1, t_vec *p2);
t_vec       v_normcy(t_vec *v1);
t_vec       cross_p(t_vec a, t_vec b);
t_vec       v_3(float x, float y, float z);
t_vec       normalize(t_vec *p);
t_vec       v_scale(float scale, t_vec *vec);
t_vec       v_sub(t_vec *v1, t_vec *v2);
t_vec       v_from_2p(t_vec v1, t_vec v2);
t_vec       v_add(t_vec *v1, t_vec *v2);
t_vec       v_mult(t_vec *v1, t_vec *v2);

/* ray */
void ray_init(t_ray **r);
t_vec *ro_3(t_ray *ray, t_vec *where);
t_vec *rd_3(t_ray *ray, t_vec *where);
t_ray *ray_prime(t_ray *ray, t_vec *origin);
t_ray ray_from_to(t_vec *point_origin, t_vec *point_direction);

#endif
