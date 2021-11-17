/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:24:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/10/18 14:30:30 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIB: <stdlib.h>
** SYN: converts string characters into their value int, my version might be
** slower than the iteractive version, felt cute might change it later.
** DESC: skips all white-space characters at the beginning of
** the string, converts the subsequent characters as part of the number,
** and then stops when it encounters the first character that isn't a number.
** (｡◕‿◕｡)
*/

#include "libft.h"

static int	ft_ratoi(const char *str, int i)
{
	if (!*str || *str > '9' || *str < '0')
		return (i);
	i = i * 10 + (*str - '0');
	return (ft_ratoi(++str, i));
}

int	ft_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		return (-ft_ratoi(++str, 0));
	if (*str == '+')
		return (ft_ratoi(++str, 0));
	return (ft_ratoi(str, 0));
}
