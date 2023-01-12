/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:17:59 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/05/24 23:03:15 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/* void	mem_error()
{
	write(1, "Error\n", 6);
	return(0);
} */

void	str_alloc(char **str, char *data)
{
	*str = NULL;
	*str = malloc(ft_strlen(data) + 1);
	if (!*str)
	{
		printf("Error: str_alloc failed");
		exit (0);
	}
}
