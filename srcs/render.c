/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/03 11:38:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int compute_light(t_frame *rt, t_obj obj, t_ray *ray, t_vec obj_coord, int hit)
{
    float albedo = 0.18;
    t_vec to_surface = v_add(&obj_coord, &obj_coord);
    uint32_t new_color;
    t_color shade;
    t_vec point_hit;
    t_vec dist;
    t_vec dir;
    float blend;

    to_surface = v_add(rt->scene->light_coord, &point_hit);
    // t_vec l = normalize(rt->scene->cam_coord);
    dir = v_scale(hit, &ray->dir);
    dist = v_sub(rt->scene->cam_coord, &ray->dir);
    /*     if(hit > 0)
        {
           point_hit = v_add(&ray->start, &dir);
           shade = c_blend(hit, obj.obj_color);
           new_color = ascii_to_hex(shade.r, shade.g, shade.b);
        return(new_color);
        } */

    point_hit = v_add(&ray->start, &dir);
    blend = (1 - hit) * 0;
    float angle = dot_p(&point_hit, &dir);
    int color = (albedo / M_PI) * rt->scene->brightness * rt->scene->ambient * angle;
    shade = c_blend(color + hit, obj.obj_color);
    printf("\t COLOR OF OBJ %u\n", obj.obj_color->hex);
    new_color = ascii_to_hex(shade.r, shade.g, shade.b);
    printf("\t COLOR 2 BLEND %u\n", color);
    printf("\t NEW COLOR %u\n", new_color);
    return (new_color);
}
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    size_t offset;

    offset = y + x;
    /*     printf("line lenght: %d\n", data->line_length);
        printf("bpp: %d\n", data->bits_per_pixel);
        printf("x: %d\n", x);
        printf("y: %d\n", y);
        exit(0); */
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
    t_vec world2scene;

    printf("IN COMPUTE SPHERE\n");
    ray.dir.x = 0;
    ray.dir.y = 0;
    ray.dir.z = 1;
    x = 0;
    y = 0;
    world2scene.x = (rt->window_w / 2);
    world2scene.y = (rt->window_h / 2);
    world2scene.z = rt->scene->cam_coord->z * -1;
    ray.start.z = world2scene.z;
    t_color shade;

    // uint32_t colors = obj->obj_color->hex;

    while (y < rt->window_h)
    {
        x = 0;
        ray.start.y = y;
        while (x < rt->window_w)
        {
            ray.start.x = x;
            hit = ray_sphere(&ray, obj, v_add(&world2scene, obj->obj_coord));
            if (hit != NO_HIT && hit <= 0)
            {
                // colors = compute_light(rt, *obj, &ray, *obj->obj_coord, hit);
                shade = c_blend(hit, obj->obj_color);
                //my_mlx_pixel_put(&rt->obj_img, x, y, shade.hex);
                mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, x, y, (shade.hex));
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
    compute_obj(rt->objs_first, rt);
    return(0);

}
