/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/18 22:46:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

char *parse_input(int fd)
{
	char *data = NULL;
	data = get_next_line(fd);
	//printf("parsing:%s\n", data);
	return(data);
}

char *save_raw(char *input)
{
	char *raw = NULL;
	int i = 0;
	raw = malloc(ft_strlen(input));
	//write(1, "copy_in\n", 8);
	while(input[i])
	{
		raw[i] = input[i];
		i++;
	}
	raw[i] = 0;
	//write(1, "copy_out\n", 9);
	//printf("returning copy\n");
	return(raw);
}