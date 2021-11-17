/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:24:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/18 14:39:15 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <strings.h>
** SYN: write 0 to a byte string
** DESC: The memcpy() function
** operates as efficiently as possible on memory areas.
** It does not check for overflow of any receiving memory area.
** Specifically, memcpy() copies n bytes from memory area s2 to s1.
** It returns s1.
** (｡◕‿◕｡)
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
