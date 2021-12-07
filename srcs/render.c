/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/07 20:41:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_light(t_frame *rt, t_ray *ray, t_vec obj_coord, t_color volume)
{
    float albedo = 0.18;
    float difuse;
    t_color color;
    float light_incident;
    float light_energy;
    t_vec surface_normal;
    t_vec p;
    //t_vec light2world;

    p = v_add(&ray->start, &ray->dir);
    surface_normal = v_sub(&p, &obj_coord);
    light_energy = rt->scene->brightness * ((v_mag(&obj_coord, rt->scene->light_coord)));
    t_vec light_ray = v_add(rt->scene->light_coord, &surface_normal);
    light_incident = MIN(dot_p(&light_ray, &surface_normal), light_energy);

    difuse = P(light_incident) * albedo;
    color = c_luminance(difuse, &volume);
    /* printf("colorx : %u\n", color.hex); */
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
    int n;
    int fov = 35;

    n = rt->scene->cam_coord->z * (sin(fov) / sin(55));
    t_vec cam_world2scene;
    t_vec obj_world2scene;

    printf("IN COMPUTE SPHERE\n");
    ray.dir.x = 0;
    ray.dir.y = 0;
    ray.dir.z = 1;
    x = 0;
    y = 0;

    cam_world2scene = world2scene(rt->window_w, rt->window_h, rt->scene->cam_coord);
    ray.start.z = cam_world2scene.z;
    obj_world2scene = world2scene(rt->window_w, rt->window_h, obj->obj_coord);
    t_color volume;
   // t_color shade;
    float light;

    // uint32_t colors = obj->obj_color->hex;

    while (y < rt->window_h)
    {
        x = 0;
        ray.start.y = y;
        while (x < rt->window_w)
        {
            ray.start.x = x;
            hit = ray_sphere(&ray, obj, obj_world2scene);
            if (hit != NO_HIT && hit <= 0)
            {
                volume = c_blend(hit, obj->obj_color);
                light = compute_light(rt, &ray, obj_world2scene, volume);
                volume = c_blend((hit + light * 0.2), obj->obj_color);
                //shade.hex = compute_light(rt, &ray, v_add(&world2scene, obj->obj_coord), volume);
                //colors = compute_light(rt, *obj, &ray, *obj->obj_coord, hit);
                //my_mlx_pixel_put(&rt->obj_img, x, y, shade.&hex);
                mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, (volume.hex));
            }
            x++;
        }
        y++;
    }
}

void compute_obj(t_obj *obj, t_frame *rt)
{
    // compute_sphere(obj, rt);
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
    int i  = 0;
    t_obj *current;
    current = rt->objs_first;
    
    while(++i <= rt->nbr_objs)
    {
        printf("index objs: %d\n", i);
        compute_obj(current, rt);
  /*       printf("curr raw: %s\n", current->raw);
        printf("next: %p\n", current->next);
        printf("current ID: %d\n", current->id2);
        printf("current x cord: %f\n", current->obj_coord->x);
        printf("next raw: %s\n", current->next->raw);
        printf("current->next ID: %d\n", current->next->id2);
        printf("next x cord: %f\n", current->next->obj_coord->x); */
        //exit(0);
        current = current->next;
    }
    //exit(0);
    return(0);

}
