/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:58 by user              #+#    #+#             */
/*   Updated: 2022/06/09 09:24:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	prompt_options(void)
{
	printi("FOR MANUAL FOCUS PRESS [m] + ENTER", 'p');
	printi("TO STAY IN AUTOMATIC PRESS [a] + ENTER", 'p');
}

void set_focus(t_frame *rt)
{
	char	focus;

	prompt_options();
	while(read(0, &focus, 1))
	{		
		if(focus != 'a' && focus != 'm')
		{
			printi("INVALID SETTING, ONE ATTEMPT LEFT", 'p');
			prompt_options();
		}
		else
			break ;
	}
	if(focus)
		rt->auto_focus = focus;
	else
		{
			printi("INVALID SETTING, NONE ATTEMPTS LEFT\n RENDERING IN AUTO FOCUS MODE", 'r');
			rt->auto_focus = 'a';
		}
	return ;
}
