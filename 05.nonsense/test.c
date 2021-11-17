/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:04:25 by user              #+#    #+#             */
/*   Updated: 2021/04/12 10:22:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int     main(void)
{
    void    *mlx;
    void    *mlx_window;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
}

