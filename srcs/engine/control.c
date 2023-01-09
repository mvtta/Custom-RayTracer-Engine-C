/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:28:56 by user              #+#    #+#             */
/*   Updated: 2022/06/09 10:11:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "control.h"

int	key_kill(int keycode, t_frame *rt)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 1216 || keycode == 53)
	{
		printi("▬▬ι═══════ﺤ KILLING RT -═══════ι▬▬", 'r');
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
		kill_frame(rt);
		printi("▬▬ι═══════ﺤ TERMINATED -═══════ι▬▬", 'r');
		exit(0);
	}
	if (keycode == 34)
		zoom_in(keycode, rt);
	if (keycode == 31)
		zoom_out(keycode, rt);
	if (keycode == 40)
		light_left(keycode, rt);
	if (keycode == 37)
		light_right(keycode, rt);
	if (keycode == 126)
		cam_up(keycode, rt);
	if (keycode == 125)
		cam_down(keycode, rt);
	if (keycode == 123)
		cam_left(keycode, rt);
	if (keycode == 124)
		cam_right(keycode, rt);
	return(0);
}
