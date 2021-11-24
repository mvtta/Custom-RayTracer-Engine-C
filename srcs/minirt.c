/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/24 09:51:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int minirt(void)
{
    t_frame *rt;
    rt = init_frame();
    fill_frame(rt);
    create_scene(rt);
    window_init(rt);
    create_objs(rt);
    render(rt);
    write(1, "render out\n", 11);
    mlx_loop(rt->mlx_ptr);
    return(0);
}

int main(int ac, char **av)
{
    int end = 0;

    end = ft_strlen(av[1]);
    if (ac == 2)
    {
        if (av[1][end - 3] == '.' 
        && av[1][end - 2] == 'r' 
        && av[1][end - 1] == 't')
        minirt();
        return(1);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}