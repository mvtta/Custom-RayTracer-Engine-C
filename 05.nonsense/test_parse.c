/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:02:16 by user              #+#    #+#             */
/*   Updated: 2021/04/29 11:18:28 by mvaldeta         ###   ########.fr       */
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

/* int trim_n_put(char identifier, char *data, t_all objects)
{
    int i;
    i = 0;
    if(str[i] != identifier)
        return(-3);
    i=+1;
    while (str[i] != '\0')
        atof(&str[i]);
} */

int parse_data(t_file_data data)
{
    printf("saved data as resolution%s", data.res);
    return(0);
}

int parse_file(int fd, t_file_data data, char **argv, int r)
{
        char *line;
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
        r = get_next_line(fd, &line);
        data.plane = line;
        printf("%s\n", data.plane);
        r = get_next_line(fd, &line);
        data.sphere = line;
        printf("%s\n", data.sphere);
        r = get_next_line(fd, &line);
        data.square = line;
        printf("%s\n", data.square);
        r = get_next_line(fd, &line);
        data.cyl = line;
        printf("%s\n", data.cyl);
        r = get_next_line(fd, &line);
        data.tri = line;
        printf("%s\n", data.tri);
        free(line);
        parse_data(data);
        return(0);
}

int main(int argc, char **argv)
{
    t_file_data data;
    int fd;
    int i;
    int r;
    int check;

    i = 0;
    r = 0;
    if (argc > 1)
       check = parse_file(fd, data, argv, r);
    return (0);
}
