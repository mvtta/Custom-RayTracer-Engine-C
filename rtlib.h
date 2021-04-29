/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:12 by user              #+#    #+#             */
/*   Updated: 2021/04/28 18:01:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTLIB_H
#define RTLIB_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_file_data
{
    char *res;
    char *amb;
    char *cam;
    char *light;
    char *plane;
    char *sphere;
    char *square;
    char *cyl;
    char *tri;
}               t_file_data;

typedef struct s_res
{
    int x;
    int y;
}               t_res;

typedef struct s_amb
{
    double ratio;
    int r;
    int g;
    int b;

}               t_amb;

typedef struct s_cam
{
   int x;
   int y;
   int z;
   double norm_x;
   double norm_y;
   double norm_z;
   int fov;

}               t_cam;

typedef struct s_light
{
   int x;
   int y;
   int z;
   double ratio;
   int r;
   int g;
   int b;
}               t_light;

typedef struct s_sphere
{
   int x;
   int y;
   int z;
   double d;
   int r;
   int g;
   int b;
}               t_sphere;

typedef struct s_plane
{
   int x;
   int y;
   int z;
   double norm_x;
   double norm_y;
   double norm_z;
   int r;
   int g;
   int b;
}               t_plane;

typedef struct s_square
{
   int x;
   int y;
   int z;
   double norm_x;
   double norm_y;
   double norm_z;
   double side;
   int r;
   int g;
   int b;
}               t_square;

typedef struct s_cyl
{
   int x;
   int y;
   int z;
   double norm_x;
   double norm_y;
   double norm_z;
   double d;
   double h;
   int r;
   int g;
   int b;
}               t_cyl;

typedef struct s_tri
{
   int point1[3];
   int point2[3];
   int point3[3];
   int r;
   int g;
   int b;
}               t_tri;

typedef struct s_all
{
    struct t_res;
    struct t_amb;
    struct t_cam;
    struct t_light;
    struct t_sphere;
    struct t_plane;
    struct t_square;
    struct t_cyl;
    struct t_tri;

}t_all;

int get_next_line(int fd, char **line);
int parse_file(int fd, t_file_data data, char **argv, int r);
int parse_data(t_file_data data);

/* utils */
int		ft_atoi(char *str, int *nb);


#endif