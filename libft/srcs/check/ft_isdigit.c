/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:47:34 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/02/12 19:29:24 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <ctype.h>
** SYN: takes a single argument in the form of an integer and returns
** the value of type int
** DESC: takes integer as an argument, character is passed to the function.
** Internally, the character is converted to its ASCII value for the check
** (｡◕‿◕｡)
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
