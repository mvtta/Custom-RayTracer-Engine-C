/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/02/25 18:15:59 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int limit_kernel(t_frame *rt, float source, float deviation, char xy)
{
  int limit;

  if(xy == 'x')
    limit = rt->window_w;
  if(xy == 'y')
    limit = rt->window_h;
  if(deviation > limit || deviation < 0)
    return(source);
  return(deviation);
}

/* int apply_blur(int  deviation) */