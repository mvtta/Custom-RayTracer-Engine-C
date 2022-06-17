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
    printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ ", 'g');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 't');
	printi("		FOR MANUAL FOCUS PRESS [m] + ENTER", 'p');
	printi("	  TO STAY IN AUTOMATIC PRESS [a] + ENTER", 'p');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 't');
    printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ ", 'g');
}

static void	invalid_focus_opt(int try)
{
	printi("| @||  ___```````________----________ ||", 'g');
	printi("| @||  |________________ ____       | ||", 'g');
	printi("| @||    |______-     ---(_'_` /    | ||", 'g');
	printi("| @||                         ` `-' | || ", 'g');
	printi("| @||                          `____| || ", 'g');
	printi("| @||                                 || ", 'g');
	printi("| @||     INVALID OPTION              || ", 'g');
	printf("| @||     you have %d attempt left!\n", try);
	prompt_options();
}

static void focus_mode_dialog(int f)
{
	char *mode;
	if (f == 'a')
		mode = "AUTO\n";
	if (f == 'm')
		mode = "MANUAL\n";
	printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ ", 'g');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 't');
	printi("     .-------------------. ", 't');
    printi("    /--#--.------.------/| ", 'y');
    printi("    |Kodak|__Ll__| [==] || ", 't');
	printi("    |     | .--. | """" || ", 't');
	printi("    |     |( () )|      || ", 'p');
	printi("    |     | `--' |      |/ ", 't');
	printi("    `-----'------'------' ", 't');
	printi("AUTO FOCUS: ", 'b');
	printf("%s", mode);
	printi("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ ", 'g');
    printi("██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██ ██▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄██  ", 't');
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
