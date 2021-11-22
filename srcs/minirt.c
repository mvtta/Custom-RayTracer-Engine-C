/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/22 18:28:43 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int minirt(void)
{
    t_frame *rt;
    rt = init_frame();


    fill_frame(&rt);
    create_scene(&rt);
    window_init();
    create_objs(&rt);
    render(&rt);
    
    
    /* printf("nbr of obj: %d\n", rt->nbr_objs);
    printf("nbr of obj: %d\n", rt->objs_first);
    write(1, "\nobj_created\n", 15);
    write(1, "\nscene_created\n", 15);
    write(1, "\nframe_filled\n", 14); */
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