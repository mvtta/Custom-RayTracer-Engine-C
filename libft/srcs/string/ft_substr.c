/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:22:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/18 14:59:42 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: Allocates (with malloc(3)) and returns a substring from the string ’s’.
** DESC: The substring begins at index ’start’ and is of maximum size ’len’.
** (｡◕‿◕｡)
*/

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*new;

	new = malloc(len + 1);
	if (!s || !new)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
