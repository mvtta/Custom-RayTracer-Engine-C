/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/12/03 12:31:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int minirt(void)
{
    t_frame *rt;
    rt = init_frame();

    fill_frame(rt);
    write(1, "\tframe\n", 7);

    create_scene(rt);
    write(1, "\tscene\n", 7);

    window_init(rt);
    write(1, "\twindow\n", 8);

    create_objs(rt);
    write(1, "\tobjects\n", 9);

    render(rt);
    write(1, "\trender out\n", 11);

    mlx_loop(rt->mlx_ptr);
    return(0);
}

int main(int ac, char **av)
{
    int last= 0;

    last= ft_strlen(av[1]);
    if (ac == 2)
    {
        if (av[1][last- 3] == '.' 
        && av[1][last- 2] == 'r' 
        && av[1][last- 1] == 't')
        minirt();
        return(1);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}