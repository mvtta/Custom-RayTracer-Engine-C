/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:42:12 by mavaldeta         #+#    #+#             */
/*   Updated: 2021/04/30 21:23:59 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: breaks string using a delimiter. malloc & free can be used
** DESC: Allocates (with malloc(3)) and returns an array of strings obtained
** by splitting ’s’ using the character ’c’ as a delimiter.
** The array must be ended by a NULL pointer
** (。◕‿◕。)
*/

#include <stdio.h>
#include "rtlib.h"
#include "get_next_line.h"

static size_t	ft_word_count(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s++ == c)
			continue ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int				fill_aray(const char *s, char c, char **array)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
		{
			j++;
			continue ;
		}
		if (!(array[i] = malloc(sizeof(char) * (ft_word_len(s + j, c) + 1))))
			return (0);
		k = 0;
		while (s[j] != c && s[j] != '\0')
			array[i][k++] = s[j++];
		array[i][k] = '\0';
		i++;
	}
	array[i] = 0;
	return (1);
}

char			**ft_split(const char *s, char c)
{
	int		word_count;
	char	**array;

	if (!s)
		return (0);
	word_count = ft_word_count(s, c);
	if (!(array = malloc(sizeof(char *) * (word_count + 1))))
		return (0);
	if (!fill_aray(s, c, array))
		return (NULL);
	return (array);
}
