/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:46 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/01/20 20:25:36 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <strings.h>
** SYN: write 0 to a byte string
** DESC: The bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing. I called memeset and assigned to
** unsigned char c, the value of zero.
** (｡◕‿◕｡)
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
