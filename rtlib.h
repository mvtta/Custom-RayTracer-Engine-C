/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:12 by user              #+#    #+#             */
/*   Updated: 2021/05/17 16:54:39 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTLIB_H
#define RTLIB_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <float.h>
#include "get_next_line.h"
#include "mlx.h"

#define START 10
#define ID "RAclpst"
#define R 'R'
#define A 'A'
#define C 'c'
#define L 'l'
#define P 'p'
#define S 's'
#define T 't'


typedef struct    s_ele {
   void  *data;
   char  *type;
   struct s_ele *next;
}                 t_ele;


typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    
} t_data;

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

typedef struct s_data_arr
{
    char **res;
    char **amb;
    char **ambcolor;
    char **cam;
    char **camxyz;
    char **cam_norm;
    char **light;
    char **lightvec;
    char **lightcolor;
    char **plane;
    char **planexyz;
    char **plane_norm;
    char **planecolor;
    char **sphere;
    char **square;
    char **cyl;
    char **tri;
}               t_data_arr;

typedef struct s_res
{
    int x;
    int y;
}              t_res;



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

typedef struct s_plane
{
   int x;
   int y;
   int z;
   float norm_x;
   float norm_y;
   float norm_z;
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

/* vector */
typedef struct s_vec{
        float x;
        float y;
        float z;
}                t_vec;

typedef struct s_sphere
{
   int x;
   int y;
   int z;
   double d;
   int r;
   int g;
   int b;
   t_vec c;
}               t_sphere;

/* ray */
typedef struct s_ray{
   t_vec    direction;
   t_vec    origin;
   float hit;
}              t_ray;

typedef struct    s_hit{
    t_sphere* sphere;
    t_vec n;
    t_vec p;
    float t;
}                 t_hit;

typedef struct s_rgbf{
    float r;
    float g;
    float b;
}              t_rgbf;

/* struct s_nested
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

}t_nested; */

struct t_nested *elem;

int         get_next_line(int fd, char **line);
t_res       parse_file(int fd, t_file_data data, char **argv, int r);
t_res       parse_data(t_file_data data);

/* utils */
int         ft_atoi(const char *str);
char        **ft_split(const char *s, char c);
int         fill_aray(const char *s, char c, char **array);
float       ft_atof(char *str);
int         match(char *str, int c);
t_ele	      *ft_lstnew(void *content);
void			ft_lstadd_back(t_ele **lst, t_ele *(new));


/*colors*/
t_rgbf new_rgb(float red, float green, float blue);
t_rgbf scale_rgb(t_rgbf color, float value);
t_rgbf addRGB(t_rgbf a, t_rgbf b);

/* vectors */
t_vec new_v(float x, float y, float z);
float mag(t_vec v);
float dot(t_vec a, t_vec b);
t_vec scale_v(float value, t_vec v);
t_vec cross(t_vec a, t_vec b);
t_vec add_v(t_vec a, t_vec b);
t_vec minus_v(t_vec a, t_vec b);

/* intersect */
float scene_hit(t_ray ray, t_hit* hit, t_sphere sphere);
float intersection(t_ray ray, t_sphere sphere);


#endif