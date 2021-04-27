/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:02:16 by user              #+#    #+#             */
/*   Updated: 2021/04/27 20:51:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

int str_create(size_t size)
{
    char *str;
    int i;

    i = 0;
    str = malloc(sizeof(char) * size + 1);
    if (!str)
        return (-1);
    while (size-- && i++)
        str[i] = '\0';
    i = +1;
    str[i] = '\0';
    return (i);
}

int parse_file(int fd, char **line)
{
    return(0);
}

int main(int argc, char **argv)
{
    static char arch[4094];
    char **buff;
    char *line;
    t_file_data data;
    int fd;
    int i;
    int r;

    i = 0;
    r = 0;
    if (argc > 1)
    {
        printf("\033[1;35m");
        printf("while I'm parsing your scene, go on and eat a dumplin...\n");
        printf("\033[0m");
        fd = open(argv[1], O_RDONLY);
        r = get_next_line(fd, &line);
        data.res = line;
        printf("%s\n", data.res);
        r = get_next_line(fd, &line);
        data.amb = line;
        printf("%s\n", data.amb);
        r = get_next_line(fd, &line);
        data.cam = line;
        printf("%s\n", data.cam);
        r = get_next_line(fd, &line);
        data.light = line;
        printf("%s\n", data.light);
        free(line);
        return(0);
    }
    return (0);
}
