/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/02/24 18:20:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

float compute_obj(t_ray *ray, t_obj *obj)
{
    float t;
    if (obj->id1 == PLANE)
        t = ray_plane(ray, obj);
    if (obj->id1 == SPHERE)
        t = ray_sphere(ray, obj, *obj->obj_coord);
    if (obj->id1 == 'c')
        t = ray_cy(ray, obj, *obj->obj_coord);
    return (t);
}

/*   static void test_ray(t_ray *r, t_vec *o)
{
    // r->start = malloc(sizeof(t_vec));
    r->start = o;
} */

static void fake_init(t_ray **r)
{
    *r = malloc(sizeof(t_ray));
    (*r)->start = malloc(sizeof(t_vec));
    (*r)->dir = malloc(sizeof(t_vec));
    (*r)->norm = malloc(sizeof(t_vec));
    (*r)->len = 0;
}
int render(t_frame *rt)
{
    t_color volume;
    t_obj *current;
    t_ray *ray;
    float hit;
    int i;
    float x;
    float y = 0;

    // ray = ray_prime(ray, rt->scene->c->cam_coord);

    // ray = ray_init();
    fake_init(&ray);
    ray->start = ro_3(ray, rt->scene->c->cam_coord);
    ray->norm = rt->scene->c->cam_norm;
    float focal_l;
    focal_l = rt->scene->c->focal_l;

    // print_vector(*ray->start, "camtest");
    // exit(0);
    //  ray->start = ro_3(ray, rt->scene->c->cam_coord);
    // test_ray(ray, rt->scene->c->cam_coord);
    // print_vector(*ray->start, "LALA");
    // exit(0);
    ray->dir->z = ndc(rt, rt->scene->c->cam_coord->z, 'z');
    while (y < (float)rt->window_h - 1)
    {
        x = 0;
        ray->start->y = rt->scene->c->cam_coord->y;
        ray->dir->y = ndc(rt, y, 'y');
        while (x < (float)rt->window_w - 1)
        {
            ray->start->x = rt->scene->c->cam_coord->x;
            ray->dir->x = ndc(rt, x, 'x');
            i = 0;
            current = rt->objs_first;
            while (++i <= rt->nbr_objs)
            {
                hit = compute_obj(ray, current);
                if (hit != NO_HIT)
                {
                    rt->record.latest_t = hit;
                    volume = standard_re(rt, ray, current);
                    if (hit >= focal_l)
                        my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h - 1) - y, volume.hex);
                    else
                    {
                        double k1[] = {0.2, 0.4, 0.5, 0.6, 0.7};
                        double k2[] = {3.0, 2.5, 1.8, 0.8, 0.3};
                        double k3[] = {13.0, 12.5, 12.0, 11.5, 1.3};
                        double k5[] = {1.3, 3.1, 4.7, 5.2, 6.8};
                        // double k4[] = {1.3, 3.1, 6.4, 8.12, 12.8};
                        int dev_x = fmod(x, 5);
                        int dev_y = fmod(y, 5);
                        // 1/(π(1 + x2)) poisson
                        // P_{y}(x)={1/pi * (y * y / x * x + y * y)}

                        /*printf("x: %f && dev_x: %d && k[dev_x]: %f\n", x, dev_x, k1[dev_x]);
                        printf("y: %f && dev_y: %d && k[dev_y]: %f\n", y, dev_y, k2[dev_y]); */
                        /*                       printf("focal: %f\n", focal_l);
                                              printf("hit: %f\n", hit);
                                              printf("len_dist: %f\n", length(*ray->dir)); */
                        // exit(0);
                        //
                        //
                        my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h - 1) - y, volume.hex);
                        if (current->id1 == 's')
                        {
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_y]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y - k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x]), (rt->window_h - 1) - (y - k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y - k3[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k2[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k5[dev_x]), (rt->window_h - 1) - (y - k5[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_y]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                        }
                        if (current->id1 == 'p')
                        {
/* 
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_y]), (rt->window_h - 1) - (y + (1 / PI * (k2[dev_x]) * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k3[dev_y]), (rt->window_h - 1) - (y + (1 / PI * (k2[dev_y]) * k3[dev_x])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k3[dev_y]), (rt->window_h - 1) - (y + (1 / PI * (k2[dev_y]) * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k3[dev_x]), (rt->window_h - 1) - (y + (1 / PI * (k2[dev_x]) * k3[dev_x])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y + (1 / PI * (k2[dev_x]) * k3[dev_y])), DEC(volume.r, volume.g, volume.b)); */
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_y]), (rt->window_h - 1) - (y + k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y + k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x]), (rt->window_h - 1) - (y + k3[dev_y]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y + k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x]), (rt->window_h - 1) - (y + k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y + k3[dev_y]), DEC(volume.r, volume.g, volume.b));

                        }
                    }
                }
                current = current->next;
            }
                x++;
        }
            y++;
        // printf("here\n");

    }
        mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->obj_img.img_ptr, 0, 0);
        return (0);
}



                            /*                         my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x]), (rt->window_h - 1) - (y - k3[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y - k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x]), (rt->window_h - 1) - (y - k3[dev_x]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y]), (rt->window_h - 1) - (y - k3[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k2[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k2[dev_x]), DEC(volume.r, volume.g, volume.b)); */
                            /*                         my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k2[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k2[dev_x]), DEC(volume.r, volume.g, volume.b)); */
                            /*                         my_mlx_pixel_put(&rt->obj_img, x + (k5[dev_y]), (rt->window_h - 1) - (y - k5[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k5[dev_x]), (rt->window_h - 1) - (y - k5[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_x]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_y]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y - k1[dev_y]), DEC(volume.r, volume.g, volume.b)); */
                            /*                      my_mlx_pixel_put(&rt->obj_img, x + (k5[dev_y]), (rt->window_h - 1) - (y - k4[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                 my_mlx_pixel_put(&rt->obj_img, x + (k4[dev_y]), (rt->window_h - 1) - (y - k5[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                 my_mlx_pixel_put(&rt->obj_img, x + (k4[dev_x]), (rt->window_h - 1) - (y - k2[dev_x]), DEC(volume.r, volume.g, volume.b));
                                                 my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_y]), (rt->window_h - 1) - (y - k2[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                 my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y - k4[dev_y]), DEC(volume.r, volume.g, volume.b));
                                                 my_mlx_pixel_put(&rt->obj_img, x + (k4[dev_x]), (rt->window_h - 1) - (y - k2[dev_x]), DEC(volume.r, volume.g, volume.b)); */
                            /*   my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_y]) * k4[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_x] * k2[dev_x])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_x]) * k4[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_x] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k2[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_x])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                              my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_y]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k3[dev_y])), DEC(volume.r, volume.g, volume.b)); */
                            /*  my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_x]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_y]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_x] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_y]) * k4[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_x] * k2[dev_x])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_x]) * k4[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_x] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k2[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_x])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_x] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_y]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_y]) * k1[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k3[dev_x])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k1[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_x])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k3[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                             my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_y]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k2[dev_x])), DEC(volume.r, volume.g, volume.b)); */
                            // my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k2[dev_x])), DEC(volume.r, volume.g, volume.b));
                            /* my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k1[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k1[dev_y] * k1[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_x]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                            my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k1[dev_x]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k1[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b)); */

                            /*                     my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * k3[dev_x] * k3[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k3[dev_y])), DEC(volume.r * (1 / PI * k3[dev_y]), volume.g * (1 / PI * k3[dev_y]), volume.b * (1 / PI * k3[dev_y])));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * k3[dev_y] * k3[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_x] * k3[dev_x])), DEC(volume.r * (1 / PI * k3[dev_x]), volume.g * (1 / PI * k3[dev_y]), volume.b * (1 / PI * k3[dev_x])));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k5[dev_x]) * k5[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k5[dev_y] * k5[dev_y])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x, (rt->window_h - 1) - (y), volume.hex);
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k5[dev_y]) * k5[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k5[dev_x] * k5[dev_y])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k5[dev_y]) * k5[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k5[dev_x] * k5[dev_x])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * k5[dev_x] * k5[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k5[dev_x] * k5[dev_y])), DEC(volume.r * (1 / PI * k5[dev_y]), volume.g * (1 / PI * k3[dev_y]), volume.b * (1 / PI * k3[dev_y])));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * k5[dev_y] * k5[dev_y]), (rt->window_h - 1) - (y - (1 / PI * k5[dev_x] * k5[dev_x])), DEC(volume.r * (1 / PI * k5[dev_x]), volume.g * (1 / PI * k5[dev_y]), volume.b * (1 / PI * k5[dev_x])));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])),  DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k2[dev_y])),  DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k1[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k1[dev_y] * k1[dev_y])),  DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k4[dev_x]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k4[dev_y] * k2[dev_y])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k2[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k2[dev_y] * k4[dev_y])), DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k3[dev_x]) * k1[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k3[dev_y])),  DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k2[dev_x]) * k3[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k3[dev_y] * k2[dev_y])),  DEC(volume.r, volume.g, volume.b));
                                                my_mlx_pixel_put(&rt->obj_img, x + (1 / PI * (k1[dev_x]) * k4[dev_x]), (rt->window_h - 1) - (y - (1 / PI * k1[dev_y] * k2[dev_y])),  DEC(volume.r, volume.g, volume.b)); */
                            /*                         my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_x]), (rt->window_h - 1) - (y + (k1[dev_y])), 16759808);
                                                    my_mlx_pixel_put(&rt->obj_img, x + (k1[dev_y]), (rt->window_h - 1) - (y + (k1[dev_x])), 255); */
                            /*        my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_x] * k3[dev_x]),  (rt->window_h - 1) - (y + k3[dev_y] * k3[dev_y]), 47814);
                                   my_mlx_pixel_put(&rt->obj_img, x + (k2[dev_x]), (rt->window_h - 1) - (y + k2[dev_y]), 255);
                                   my_mlx_pixel_put(&rt->obj_img, x + (k3[dev_y] * k3[dev_x]),  (rt->window_h - 1) - (y + k3[dev_y] * k3[dev_x]), 10447814); */