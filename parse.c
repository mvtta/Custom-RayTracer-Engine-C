/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:20:21 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/17 18:01:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

char *parse_input(void)
{
	char *line;
	line = get_next_line(0);
	return(line);
}

char *save_raw(char *input)
{
	char *raw = NULL;
	int i = 0;
	raw = NULL;
	raw = malloc(ft_strlen(input));
	while(input[i])
	{
		raw[i] = input[i];
		i++;
	}
	raw[i] = 0;
	return(raw);
}