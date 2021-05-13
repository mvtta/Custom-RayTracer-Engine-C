/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/13 21:55:27 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"
#include <math.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    /* address + calculate memory oftset */
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int main(int argc, char **argv)
{
    t_data img;
    t_file_data data;
    t_res resolution;
    
    void *mlx;
    void *mlx_win;
    int fd;
    int i;
    int r;
    int put_backgr_x = 40;
    int put_backgr_x1 = 45;
    int put_linex = 0;
    int put_backgr_y = 0;
    int color[2] = {0x090979, 0xffc3a0};

    i = 0;
    r = 0;
    fd = open(argv[1], O_RDONLY);
    if (argc > 1)
        resolution = parse_file(fd, data, argv, r);
    close(fd);
    
    printf("\nhey x resolution here :%d\n", resolution.x);
    printf("\nhey x resolution here :%d\n", resolution.y);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, resolution.x, resolution.y, "Hello world!");
    img.img = mlx_new_image(mlx, resolution.x, resolution.y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    /* pink square */
    while (put_backgr_x < resolution.x)
    {
        my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x, 0xFFA500);
        mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x, put_backgr_y / 2);
        put_backgr_x++;
    }
        printf("here");
        exit(0);
    while (put_backgr_x1 < resolution.y)
    {
        //my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x1, 0xffff00);
        //mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x1, put_backgr_y / 2);
        put_backgr_x1++;
    }
    /* make a grid */
    put_backgr_y = 1920 / 2;
    while (put_linex < 1200)
    {
        my_mlx_pixel_put(&img, put_backgr_y, put_linex, 0xFFA500);
        //mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x1, put_backgr_y / 2);
        put_linex++;
        
    }
    put_backgr_x = 0;
    put_backgr_y = 0;
    while (put_backgr_x < 1000 && put_backgr_y < 1000)
    {
        //verde
        my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x, 0x0ddd6f3);
        mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x, put_backgr_y / 2);
        put_backgr_y *= 2;
        put_backgr_x *= 2;
        put_backgr_y++;
        put_backgr_x++;
    }
    put_backgr_x = 1200 / 2;
    put_backgr_y = 1920 / 2;
    while (put_backgr_x > 0 && put_backgr_y > 0)
    {
        //verde
        my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x, 0x36d1dc);
        mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x / 2, put_backgr_y / 2);
        put_backgr_y--;
        put_backgr_x--;
    }
    mlx_loop(mlx);
    return (0);
}