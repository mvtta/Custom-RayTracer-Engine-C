/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/18 17:47:25 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

char *parse_input(int fd)
{
	printf("parsing:\n");
	return(get_next_line(fd));
}

char *save_raw(char *input)
{
	char *raw = NULL;
	int i = 0;
	raw = malloc(ft_strlen(input));
	printf("entering copy\n");
	while(input[i])
	{
		raw[i] = input[i];
		i++;
	}
	raw[i] = 0;
	printf("returning copy\n");
	return(raw);
}