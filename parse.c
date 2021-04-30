/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/30 21:39:20 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

int parse_data(t_file_data data)
{
	printf("\n%s", data.res);
	printf("\n%s", data.amb);
	printf("\n%s", data.cam);
	printf("\n%s", data.light);
	printf("\n%s", data.plane);
	printf("\n%s", data.sphere);
	printf("\n%s", data.square);
	printf("\n%s", data.cyl);
	printf("\n%s", data.tri);
	char **arr_res = ft_split(data.res, ' ');
	char **arr_amb = ft_split(data.amb, ' ');
	char **arr_cam = ft_split(data.cam, ' ');
	char **arr_light = ft_split(data.light, ' ');
	char **arr_plane = ft_split(data.plane, ' ');
	char **arr_sphere = ft_split(data.sphere, ' ');
	char **arr_square = ft_split(data.square, ' ');
	char **arr_cyl = ft_split(data.cyl, ' ');
	char **arr_tri = ft_split(data.tri, ' ');
	int i = 0;
	while(arr_cyl[i])
	{
		printf("\n%s", arr_cyl[i]);
		i++;
	}
	t_res res;
	return (0);
}

int parse_file(int fd, t_file_data data, char **argv, int r)
{
	char *line;
	printf("\033[1;35m");
	printf("Hi, miniRT here 🦄\nWhile I'm parsing your scene, go on and eat a dumplin 🥟 ...\n");
	printf("\033[0m");
	r = START;
	while (r > 0)
	{
		r = get_next_line(fd, &line);
		if (line[0] == 'R')
			data.res = line;
		if (line[0] == 'A')
			data.amb = line;
		if (line[0] == 'c' && line[1] == ' ')
			data.cam = line;
		if (line[0] == 'l')
			data.light = line;
		if (line[0] == 'p' && line[1] == 'l')
			data.plane = line;
		if (line[0] == 's' && line[1] == 'p')
			data.sphere = line;
		if (line[0] == 's' && line[1] == 'q')
			data.square = line;
		if (line[0] == 't')
			data.tri = line;
		if (line[0] == 'c' && line[1] == 'y')
			data.cyl = line;
		printf("%s\n", line);
	}
	parse_data(data);
	return (0);
}