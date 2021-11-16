#include "mlx.h"
#include <math.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    /* address + calculate memory oftset */
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void *my_circle(t_data img, int radius)
{
    int i;
    int j;

    i = 0;
    while (i++ < 2 * radius)
    {
        j = 0;
        while (j++ < 2 * radius)
        {
            double distance = sqrt((double)(i - radius) * (i - radius) + (j - radius) * (j - radius));
            if (distance > radius - 0.5 && distance < radius + 0.5)
                my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
        }
    }
    return (0);
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}