/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:34:32 by user              #+#    #+#             */
/*   Updated: 2021/04/30 23:13:37 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int			ft_atoi(const char *str)
{
	int i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r')
		i++;
	int mynb;
	
	while(str[i] != '\0')
	{
			mynb = mynb * 10 + 48;
			i++;
		
	}
	return(mynb);
}
