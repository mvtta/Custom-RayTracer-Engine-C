/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:15:12 by user              #+#    #+#             */
/*   Updated: 2021/04/27 20:24:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTLIB_H
#define RTLIB_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_file_data
{
    char *res;
    char *amb;
    char *cam;
    char *light;
    char *plane;
    char *square;
    char *cyl;
    char *tri;
}               t_file_data;

int parse_file(int fd, char **line);
int str_create(size_t size);
int get_next_line(int fd, char **line);

#endif