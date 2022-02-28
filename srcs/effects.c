/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/02/27 19:25:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int limit_kernel(t_frame *rt, float source, float deviation, char xy)
{
  int limit;

  if(xy == 'x')
    limit = rt->window_w -1;
  if(xy == 'y')
    limit = rt->window_h -1;
  if(deviation > limit)
    return(limit);
  if(deviation < 0)
    return(source);
  return(deviation);
}

/* int apply_blur(int  deviation) */