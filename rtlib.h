/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:12 by user              #+#    #+#             */
/*   Updated: 2021/05/18 18:41:20 by user             ###   ########.fr       */
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
typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct s_sphere
{
   int x;
   int y;
   int z;
   double d;
   int r;
   int g;
   int b;
   t_vector c;
}               t_sphere;

typedef struct s_rgb{
    int r;
    int g;
    int b;
}              t_rgb;

/* ray */
typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
	double		ray_t;
	t_vector	ray_n_t;
	t_rgb		ray_color;
	void		*obj;
}				t_ray;

typedef struct    s_hit{
    t_sphere* sphere;
    t_vector n;
    t_vector p;
    float t;
}                 t_hit;


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
t_rgb new_rgb(float red, float green, float blue);
t_rgb scale_rgb(t_rgb color, float value);
t_rgb addRGB(t_rgb a, t_rgb b);

/* vectors */
t_vector new_v(float x, float y, float z);
float mag(t_vector v);
float dot(t_vector a, t_vector b);
t_vector scale_v(float value, t_vector v);
t_vector cross(t_vector a, t_vector b);
t_vector add_v(t_vector a, t_vector b);
t_vector minus_v(t_vector a, t_vector b);

/* intersect */
float scene_hit(t_ray ray, t_hit* hit, t_sphere sphere);
float intersection(t_ray ray, t_sphere sphere);

void    ray_tracer(t_data img, int x, int y);
t_rgb trace(t_ray ray, t_sphere sphere);
int		color_to_int(t_rgb rgb);
void	my_pixel_put(t_data *data, t_res resolution, t_rgb *rgb);


#endif