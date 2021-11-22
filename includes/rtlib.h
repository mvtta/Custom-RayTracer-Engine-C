/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:12 by user              #+#    #+#             */
/*   Updated: 2021/11/22 18:35:46 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTLIB_H
# define RTLIB_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <float.h>
#include <mlx.h>

#include "mlx.h"
#include "gnl.h"
#include "libft.h"

typedef struct s_vec
{
    float x;
    float y;
    float z;
}t_vec;

typedef struct s_color
{
    int r;
    int b;
    int g;
    unsigned int hex;
    
}t_color;

typedef struct s_obj
{
    char id1;
    char id2;
    struct s_obj *prev;
    struct s_obj *next;
    char *raw;
    t_vec *obj_coord;
    t_color *obj_color;
    t_vec *obj_norm;
    float diameter;
    float height;
    

}t_obj;

typedef struct s_scene
{
    char *id;
    /* A */
    float ambient;
    t_color *amb_color;
    /* C */
    t_vec *cam_coord;
    t_vec *cam_norm;
    int fov;
    /* L */
    t_vec *light_coord;
    float brightness;
    t_color *light_color;
}t_scene;

typedef struct s_frame
{
    char *ambient;
    char *camera;
    char *light;
    /* 🔺these are alocated separatly please 
    free after use thanks */
    t_scene *scene;
    t_obj *objs_first;
    t_obj *objs_last;
    int nbr_objs;
    t_data *images;
}t_frame;

/* mlx struct */

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* prototypes */

/* render.c */

int render(t_frame *rt);

/* image.c */

t_data *create_image();

/* window.c */

void window_init(void);


/* ascii_to.c */

int ascii_to_int(char *data);
float ascii_to_float(char *data);
t_vec *ascii_to_vec(char *data);
t_vec *ascii_to_vec(char *data);
unsigned int ascii_to_hex(int r, int g, int b);
t_color *ascii_to_rgb(char *data);

/* create_obj.c */
t_obj *new_obj(t_frame *rt, char *data);
void add_new_obj(t_frame *rt, char *data);
void create_sphere(t_obj *obj, char *data);

/* create_scene.c */
void create_scene(t_frame *rt);
void create_objs(t_frame *rt);

/* scene.c */

t_scene *init_scene(void);

/* fill_scene.c */

t_scene *att_ambient(t_scene *scene, char **data);
t_scene *att_camera(t_scene *scene,char **data);
t_scene *att_light(t_scene *scene, char **data);
t_frame *attribute(t_frame *rt,t_scene *scene, char id, char *data);
void fill_scene(t_frame *rt, char id);

/* frame.c */

t_frame *init_frame(void);
t_frame *fill_frame(t_frame *rt);
t_frame *kill_frame(t_frame *rt);

/* parse.c */
char *parse_input(int fd);
char *save_raw(char *input);

/* minirt.c */

size_t ft_strlen(const char *str);
int minirt(void);

#endif