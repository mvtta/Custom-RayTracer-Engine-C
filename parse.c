/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/13 21:51:47 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

t_res parse_data(t_file_data data)
{
	t_data_arr arr;
	t_amb amb;
	t_cam cam;
	t_light light;
	t_plane plane;
	t_res res;
	printf("\n%s", data.res);
	printf("\n%s", data.amb);
	printf("\n%s", data.cam);
	printf("\n%s", data.light);
	printf("\n%s", data.plane);
	printf("\n%s", data.sphere);
	printf("\n%s", data.square);
	printf("\n%s", data.cyl);
	printf("\n%s", data.tri);
	arr.res = ft_split(data.res, ' ');
	arr.amb = ft_split(data.amb, ' ');
	arr.cam = ft_split(data.cam, ' ');
	arr.camxyz = ft_split(arr.cam[1], ',');
	arr.cam_norm = ft_split(arr.cam[2], ','); 
	arr.ambcolor = ft_split(arr.amb[2], ',');
	arr.light = ft_split(data.light, ' ');
	arr.lightvec = ft_split(arr.light[1], ',');
	arr.lightcolor = ft_split(arr.light[3], ',');
	arr.plane = ft_split(data.plane, ' ');
	arr.planexyz = ft_split(arr.plane[1], ',');
	arr.plane_norm = ft_split(arr.plane[2], ',');
	arr.planecolor = ft_split(arr.plane[3], ',');
	arr.sphere = ft_split(data.sphere, ' ');
	arr.square = ft_split(data.square, ' ');
	arr.cyl = ft_split(data.cyl, ' ');
	arr.tri = ft_split(data.tri, ' ');
	res.x = ft_atoi(arr.res[1]);
	res.y = ft_atoi(arr.res[2]);
	amb.ratio = ft_atof(arr.amb[1]);
	amb.r = ft_atoi(arr.ambcolor[0]);
	amb.g = ft_atoi(arr.ambcolor[1]);
	amb.b = ft_atoi(arr.ambcolor[2]);
	cam.x = ft_atoi(arr.camxyz[0]);
	cam.y = ft_atoi(arr.camxyz[1]);
	cam.z = ft_atoi(arr.camxyz[2]);
	cam.norm_x = ft_atoi(arr.cam_norm[0]);
	cam.norm_y = ft_atoi(arr.cam_norm[1]);
	cam.norm_z = ft_atoi(arr.cam_norm[2]);
	cam.fov = ft_atoi(arr.cam[3]);
	light.x = ft_atoi(arr.lightvec[0]);
	light.y = ft_atoi(arr.lightvec[1]);
	light.z = ft_atoi(arr.lightvec[2]);
	light.ratio = ft_atof(arr.light[2]); 
	light.r = ft_atoi(arr.lightcolor[0]);
	light.g = ft_atoi(arr.lightcolor[1]);
	light.b = ft_atoi(arr.lightcolor[2]);
	plane.x = ft_atoi(arr.planexyz[0]);
	plane.y = ft_atoi(arr.planexyz[1]);
	plane.z = ft_atoi(arr.planexyz[2]);
	plane.norm_x = ft_atof(arr.plane_norm[0]);
	plane.norm_y = ft_atof(arr.plane_norm[1]);
	plane.norm_z = ft_atof(arr.plane_norm[2]);
	plane.r = ft_atoi(arr.planecolor[0]);
	plane.g = ft_atoi(arr.planecolor[1]);
	plane.b = ft_atoi(arr.planecolor[2]);
	/* todo:fazer um atod + atof */
/* 	printf("\n%d", res.x);
	printf("\n%d", res.y);
	printf("\n%f", amb.ratio);
	printf("\n%d", amb.r);
	printf("\n%d", amb.g);
	printf("\n%d", amb.b);
	printf("\n%d", cam.x);
	printf("\n%d", cam.y);
	printf("\n%d", cam.z);
	printf("\n%f", cam.norm_x);
	printf("\n%f", cam.norm_y);
	printf("\n%f", cam.norm_z);
	printf("\n%d", cam.fov);
	printf("\n%d", light.x);
	printf("\n%d", light.y);
	printf("\n%d", light.z);
	printf("\n%f", light.ratio);
	printf("\n%d", light.r);
	printf("\n%d", light.g);
	printf("\n%d", light.b); */
	printf("\narray %s", arr.plane_norm[1]);
	printf("\n%d", plane.x);
	printf("\n%d", plane.y);
	printf("\n%d", plane.z);
	printf("\n%f", plane.norm_x);
	printf("\n%f", plane.norm_y);
	printf("\n%f", plane.norm_z);
	printf("\n%d", plane.r);
	printf("\n%d", plane.g);
	printf("\n%d", plane.b);

	return (res);
}

t_res parse_file(int fd, t_file_data data, char **argv, int r)
{
	char *line;
	printf("\033[1;35m");
	printf("Hi, miniRT here 🦄\nWhile I'm parsing your scene, go on and eat a dumplin 🥟 ...\n");
	printf("\033[0m");
	r = START;
	t_res res;
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
	res = parse_data(data);
	return (res);
}