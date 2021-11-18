/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/18 22:54:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int minirt(void)
{
    t_frame *rt;
    rt = init_frame();
    fill_frame(rt);
    create_scene(rt);
    create_objs(rt);
    return(0);
    //paint_frame;
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
    }
    else
        write(1, "Error\n", 6);
    return (0);
}