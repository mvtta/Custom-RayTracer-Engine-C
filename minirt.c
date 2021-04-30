/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:09 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/30 16:37:03 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"


int main(int argc, char **argv)
{
    t_file_data data;
    int fd;
    int i;
    int r;
    int check;

    i = 0;
    r = 0;
    fd = open(argv[1], O_RDONLY);
    if (argc > 1)
       parse_file(fd, data, argv, r);
    return (0);
}