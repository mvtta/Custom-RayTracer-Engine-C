/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:08:11 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/18 16:07:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <string.h>
** SYN: find last and return a ptr of the location of c
** DESC: searches for the flast occurrence of the character c (an unsigned char)
** in the string pointed to by the argument str.
** (｡◕‿◕｡)
*/

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*ini;

	ini = s;
	i = ft_strlen(s);
	s = (s + i);
	while (*s != *ini && (char)c != *s)
		s--;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
