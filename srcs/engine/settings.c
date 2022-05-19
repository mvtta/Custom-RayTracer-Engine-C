/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:58 by user              #+#    #+#             */
/*   Updated: 2022/05/19 10:36:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

void    prompt_options(void)
{
    printf("FOR MANUAL FOCUS PRESS 1\n");
    printf("TO STAY IN AUTOMATIC PRESS 0\n");
    usleep(2);
}

int choose_focus_mode(t_frame *rt)
{
    rt->auto_focus = 0;
    return(0);
}