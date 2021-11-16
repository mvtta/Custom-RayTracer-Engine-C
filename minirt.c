/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/16 17:22:42 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

size_t ft_strlen(const char *str)
{
    int i = 0;
    while(str[i])
        i++;
       return(i);
}

int main(int ac, char **av)
{  
    int end = 0;
    
    end = ft_strlen(av[1]);
    if(ac == 2)
    {
      if(av[1][end - 3] == '.' && av[1][end - 2] == 'r' && av[1][end -1] == 't')
      {
          printf("hurray\n");
        /* mini_rt(0); */
      }
    }
    else
        write(1, "Error\n", 6);
     return(0);
}