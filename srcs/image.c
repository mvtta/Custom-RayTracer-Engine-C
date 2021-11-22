/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:05:27 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/22 18:40:53 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_data *create_image()
{
  t_data *new_image;

  new_image = malloc(sizeof(t_data));

  new_image->addr = NULL;
  new_image->bits_per_pixel = 0;
  new_image->endian = 0;
  new_image->img = 0;
  new_image->line_length = 0;
  return(new_image);
}

void add_img_queue(t_frame *rt)
{
  
}