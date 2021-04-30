/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/30 22:51:48 by mvaldeta         ###   ########.fr       */
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
	t_data_arr arr;
	arr.res = ft_split(data.res, ' ');
	arr.amb = ft_split(data.amb, ' ');
	arr.cam = ft_split(data.cam, ' ');
	arr.light = ft_split(data.light, ' ');
	arr.plane = ft_split(data.plane, ' ');
	arr.sphere = ft_split(data.sphere, ' ');
	arr.square = ft_split(data.square, ' ');
	arr.cyl = ft_split(data.cyl, ' ');
	arr.tri = ft_split(data.tri, ' ');
	t_res res;
	int *ptr;
	printf("\n%s\n", arr.res[1]);
	res.x = ft_atoi(arr.res[1]);
	res.y = ft_atoi(arr.res[2]);
	double ttest = 0;
	char test[7] = "0.2";
	ttest = ft_atoi(test);
	/* todo:fazer um atod + atof */
	printf("\n%d", res.x);
	printf("\n%d", res.y);
	printf("\n%lf", ttest);

	/* int i = 0;
	while(arr_cyl[i])
	{
		printf("\n%s", arr_cyl[i]);
		i++;
	} */
	
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