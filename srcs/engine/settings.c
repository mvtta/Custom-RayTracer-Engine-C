/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:58 by user              #+#    #+#             */
/*   Updated: 2022/06/16 19:50:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void	prompt_options(void)
{

    printi("__________________________________________________________________\n\n", 'g');
    printi("                               Mode                               \n", 'g');
    printi(" Manual: press[m]+ enter -> chose lens type, enjoy the chromatic aberrations, emulates a Analog camera / lens behavior", 'g');
    printi(" Auto: press[a]+ enter -> sets focal point automatic with a 50 lens, emulates a Digital camera / lens behavior", 'g');
    printi("\nmanual mode is currently taking a long time to render\n todo: optimization using the monte carlo method", 'g');
    printi("__________________________________________________________________\n\n", 'g');
}

static void	invalid_focus_opt(int try)
{
	printi("__________________________________________________________________\n\n", 'g');
	printi("[INVALID OPTION]!\n", 'g');
	printi("you have %d attempt left!\n", 'g');
	prompt_options();
}

static void focus_mode_dialog(int f)
{
	char *mode;
	if (f == 'a')
		mode = "auto mode selected\n";
	if (f == 'm')
		mode = "manual mode selected\n";
	printf("%s", mode);
	printi("__________________________________________________________________\n\n", 'g');
}

void set_focus(t_frame *rt)
{
	char	focus;

	prompt_options();
	while(read(0, &focus, 1))
	{		
		if(focus != 'a' && focus != 'm')
			invalid_focus_opt(1);
			else
				break ;
		if(focus)
			rt->auto_focus = focus;
		else
		{
			invalid_focus_opt(0);
			rt->auto_focus = 'a';
		}
	}
	focus_mode_dialog(focus);
	return ;
}
