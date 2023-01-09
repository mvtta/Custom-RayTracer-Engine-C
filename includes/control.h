/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:48:48 by user              #+#    #+#             */
/*   Updated: 2022/06/10 02:25:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
#define CONTROL_H

#include "rtlib.h"
#include <ctype.h>

/* camera */
int    zoom_in(int keycode, t_frame *rt);
int    zoom_out(int keycode, t_frame *rt);

/* light */
int    light_up(int keycode, t_frame *rt);
int    light_down(int keycode, t_frame *rt);
int    light_left(int keycode, t_frame *rt);
int    light_right(int keycode, t_frame *rt);

/* cam */
int    cam_up(int keycode, t_frame *rt);
int    cam_down(int keycode, t_frame *rt);
int    cam_left(int keycode, t_frame *rt);
int    cam_right(int keycode, t_frame *rt);


#endif