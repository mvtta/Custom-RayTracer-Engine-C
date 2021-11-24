/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:53:10 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:27:03 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <ctype.h>
** SYN: checks whether a character is a printable character or not
** DESC: If a character passed to isprint() is a printable character,
** it returns non-zero integer, if not it returns 0.
** (｡◕‿◕｡)
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
