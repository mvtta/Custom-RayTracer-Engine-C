/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/15 23:38:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_light_plane(t_frame *rt, t_ray *ray, t_vec obj_coord)
{
    float difuse;
    float light_energy;
    float normal;
    t_vec plane_norm = {0,0,1};
    t_vec norm_dir = normalize(&ray->dir);
	t_vec norm_start = normalize(&ray->start);
    float denom = dot_p(&obj_coord, &norm_dir); 
    light_energy = rt->scene->brightness * denom;
    t_vec light_ray = v_sub(&plane_norm, &norm_start);
    normal = MAX(dot_p(&light_ray, &plane_norm), 0);
    difuse = (normal * light_energy * 0.18);
    //printf("DIFUSE SUPOSED TO VE A COOL VAL:\t%f\n", difuse);

    return (difuse);
}

float compute_light(t_frame *rt, t_ray *ray, t_vec obj_coord)
{
    float difuse;
    float light_energy;
    float normal;
    t_vec norm_dir = normalize(&ray->dir);
	//t_vec norm_start = normalize(&ray->start);
	t_vec sp_norm1 = normalize(&obj_coord);
    float denom = dot_p(&obj_coord, &norm_dir); 
    t_vec light = normalize(rt->scene->light_coord);
	t_vec sp_norm2 = cross_p(sp_norm1, light);
    light_energy = rt->scene->brightness * denom;
    normal = MAX(dot_p(&light, &sp_norm2), 0);
    difuse = normal * light_energy * 0.18;

    return (difuse);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    size_t offset;

    offset = y + x;
    *(unsigned int *)(data->data + offset) = color;
}

void compute_sphere(t_obj *obj, t_frame *rt)
{
    t_ray ray;
    float hit;
    int x;
    int y;

    float aspect_ratio;
    aspect_ratio = rt->window_w / rt->window_h;
    // t_vec cam_world2scene;
    t_vec obj_world2scene;

    printf("IN COMPUTE SPHERE\n");
    ray.dir.z = 1;
    x = 0;
    y = 0;

    // cam_world2scene = world2scene(rt->window_w, rt->window_h, rt->scene->cam_coord);
    ray.start.z = rt->scene->cam_coord->z;
    obj_world2scene = world2scene(rt->window_w, rt->window_h, obj->obj_coord);
    float light;

    t_color volume;

    while (y < rt->window_h)
    {
        x = 0;
        ray.start.y = rt->scene->cam_coord->y;
        ray.dir.y = -(2 * (y + 0.5) / (float)rt->window_h - 1) * tan(rt->scene->fov / 2);
        while (x < rt->window_w)
        {
            ray.start.x = rt->scene->cam_coord->x;
            ray.dir.x = (2 * (x + 0.5) / (float)rt->window_w - 1) * tan(rt->scene->fov / 2) * rt->window_w / (float)rt->window_h;
            hit = ray_sphere(&ray, obj, *obj->obj_coord);
            // printf("\thit sphere: %f\n", hit);
            if (hit != NO_HIT)
            {
                //printf("\thit sphere: %f\n", hit);
                light = compute_light(rt, &ray, *obj->obj_coord);
                volume = c_mix(hit, light, obj->obj_color);
                mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, volume.hex);
            }
            x++;
        }
        y++;
    }
}

void compute_plane(t_obj *obj, t_frame *rt)
{
    t_ray ray;
    float hit;
    int x;
    int y;

    float aspect_ratio;
    aspect_ratio = rt->window_w / rt->window_h;
    //t_vec obj_world2scene = world2scene(rt->window_w, rt->window_h, obj->obj_coord);
    // t_vec cam_world2scene = world2scene(rt->window_w, rt->window_h, rt->scene->cam_coord);

    printf("IN COMPUTE PLANE\n");
    x = 0;
    y = 0;

    float light;
    t_color volume;
    ray.dir.z = 1;
    ray.start.z = rt->scene->cam_coord->z;
    //(2*(i + 0.5)/(float)width  - 1)*tan(fov/2.)*width/(float)height
    while (y < rt->window_h)
    {
        x = 0;
        while (x < rt->window_w)
        {
            ray.start.y = rt->scene->cam_coord->y;
            ray.dir.y = -(2 * (y + 0.5) / (float)rt->window_h - 1) * tan(rt->scene->fov / 2);
            ray.start.x = rt->scene->cam_coord->x;
            ray.dir.x = (2 * (x + 0.5) / (float)rt->window_w - 1) * tan(rt->scene->fov / 2) * rt->window_w / (float)rt->window_h;
            hit = ray_plane(&ray, obj, *obj->obj_coord);
            if (hit != NO_HIT)
            {
                printf("hit plane: %f\n", hit);
                light = compute_light_plane(rt, &ray, *obj->obj_coord);
                volume = c_mix_plane(hit, light, obj->obj_color);
                mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, volume.hex);
                // printf("color: %u\n", volume.hex);
                // printf("light: %f\n", light);
            }
            x++;
        }
        y++;
    }
}

void compute_obj(t_obj *obj, t_frame *rt)
{
    // compute_sphere(obj, rt);
    if (obj->id1 == PLANE)
        compute_plane(obj, rt);
    if (obj->id1 == SPHERE)
        compute_sphere(obj, rt);
}

void background_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->bkg_img.img_ptr, 0, 0);
}

void obj_to_window(t_frame *rt)
{
    mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);
}

int render(t_frame *rt)
{
    int i = 0;
    t_obj *current;
    current = rt->objs_first;

    while (++i <= rt->nbr_objs)
    {
        printf("index objs: %d\n", i);
        compute_obj(current, rt);
        printf("curr raw: %s\n", current->raw);
        printf("curr id1: %c\n", current->id1);
        /*       printf("curr raw: %s\n", current->raw);
        printf("next: %p\n", current->next);
        printf("current ID: %d\n", current->id2);
        printf("current x cord: %f\n", current->obj_coord->x);
        printf("next raw: %s\n", current->next->raw);
        printf("current->next ID: %d\n", current->next->id2);
        printf("next x cord: %f\n", current->next->obj_coord->x); */
        // exit(0);
        current = current->next;
    }
    // exit(0);
    return (0);
}
