/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/18 19:49:43 by user             ###   ########.fr       */
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
    int j;

    i = 0;
    j = 0;
    r = 0;
    float v1, v2, v3 = 0;
    float vec_dir = 0;
    fd = open(argv[1], O_RDONLY);
    if (argc > 1)
        resolution = parse_file(fd, data, argv, r);
    close(fd);
    printf("\n%s", "hello");
    printf("\nhey x resolution here :%d\n", resolution.x);
    printf("\nhey y resolution here :%d\n", resolution.y);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, resolution.x, resolution.y, "Hello world!");
    img.img = mlx_new_image(mlx, resolution.x, resolution.y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    while(i++ < resolution.x - 1)
    {
        j=0;
        while(j++ < resolution.y - 1)
            my_mlx_pixel_put(&img, i, j, 0x5AC18E);   
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}