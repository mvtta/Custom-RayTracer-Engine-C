/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:14:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/24 13:27:59 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** (｡◕‿◕｡)utilities
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (size--)
	{
		*(str++) = '\0';
		i++;
	}
	*str = '\0';
	return (str - i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*new;

	if (!s1 || !s2)
		return (0);
	len = ((ft_strlen(s1) + ft_strlen(s2)));
	if (!(new = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	len = 0;
	while (s1[i])
		new[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		new[len] = s2[i];
		len++;
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s || !(new = malloc(len + 1)))
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
