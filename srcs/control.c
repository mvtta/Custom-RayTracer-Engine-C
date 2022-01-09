/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:28:56 by user              #+#    #+#             */
/*   Updated: 2022/01/09 17:16:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#define KRED "\x1B[31m" 

int	key_kill(int keycode, t_frame *rt)
{
    printf("keycode: %d\n", keycode);
    if(keycode == 4848)
    {
        printf("\tRED DOT\n");
        exit(EXIT_SUCCESS);
    }
    if(keycode == 53)
        printf("\tHURRAY YOU PRESSED ESCAPE\n");
    else 
        printf("\tYOU PRESSED ANY OTHER KEY\n");
    mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
    free(rt->scene);
    free(rt->objs_first);
    free(rt);
    printf("x_x Killing Mini x_x \n");
    printf("* Window killed!\n");
    printf("* Scene killed!\n");
    printf("* List killed!\n");
    printf("* Frame killed!\n");
    exit(0);
	return (keycode);
}