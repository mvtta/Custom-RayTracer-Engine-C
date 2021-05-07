/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/07 13:25:37 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

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
    t_res *res;
    void *mlx;
    void *mlx_win;
    int fd;
    int i;
    int r;
    int put_backgr_x = 40;
    int put_backgr_y = 0;
    int color[2] = {0x090979, 0xffc3a0};

    i = 0;
    r = 0;
    fd = open(argv[1], O_RDONLY);
    if (argc > 1)
        parse_file(fd, data, argv, r);
    close(fd);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1200, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1200);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    /* pink square */
    while (put_backgr_x < 200)
    {
        my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x, 0xffc3a0);
        mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x, put_backgr_y / 2);
        put_backgr_x++;
    }
    put_backgr_x = 0;
    put_backgr_y = 0;
/*     while (put_backgr_x < 1000 && put_backgr_y < 1000)
    {
        //verde
        my_mlx_pixel_put(&img, put_backgr_y, put_backgr_x, 0x0ddd6f3);
        mlx_put_image_to_window(mlx, mlx_win, img.img, put_backgr_x, put_backgr_y / 2);
        put_backgr_y *= 2;
        put_backgr_x *= 2;
        put_backgr_y++;
        put_backgr_x++;
    } */
    put_backgr_x = 1080;
    put_backgr_y = 1920;
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