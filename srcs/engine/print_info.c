/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:11:38 by user              #+#    #+#             */
/*   Updated: 2022/06/10 03:49:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	print_vector(t_vec v, char *info)
{
	printf("\t%s:\n", info);
	printf("v.x:%f\nv.y:%f\nv.z:%f\n\n", v.x, v.y, v.z);
}

void printi(char *info, char color)
{

	printf("\033[0m");
		
	if (color == 'm')
		printf("\033[1;35m");

	if (color == 'r')
		printf("\033[1;31m");
		
	if (color == 'c')
		printf("\e[1;96m");

	if (color == 'p')
		printf("\033[1;95m");
	
	if (color == 'w')
		printf("\033[1;37m");
	
	if (color == 'g')
		printf("\033[1;92m");
	
	if (color == 'y')
		printf("\033[1;33m");
	
	if (color == '.')
		printf("\033[0;105m");

	printf("%s\n", info);
}