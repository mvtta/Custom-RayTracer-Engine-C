/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:00:22 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/18 14:54:22 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: none
** SYN: joins 2 constants into a new string, dinam. allocating it.
** DESC: Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
** (｡◕‿◕｡)
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*new;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(len * sizeof(char));
	if (!(new))
		return (0);
	len = 0;
	while (*s1)
		new[len++] = *(s1++);
	while (*s2)
		new[len++] = *(s2++);
	new[len] = '\0';
	return (new);
}
