/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/18 16:27:10 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int minirt(void)
{
    t_frame *rt;
    rt = init_frame();
    printf("before fill\n");
    fill_frame(rt);
    printf("after fill\n");
    create_scene(rt);
    create_objs(rt);
    //paint_frame;
}

int main(int ac, char **av)
{
    int end = 0;

    end = ft_strlen(av[1]);
    if (ac == 2)
    {
        if (av[1][end - 3] == '.' && av[1][end - 2] == 'r' && av[1][end - 1] == 't')
        {
            printf("hurray\n");
            minirt();
        }
    }
    else
        write(1, "Error\n", 6);
    return (0);
}