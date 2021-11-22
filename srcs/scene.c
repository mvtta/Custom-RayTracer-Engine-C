/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:11 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/11/22 14:01:36 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

t_scene *init_scene(void)
{ 
  t_scene *scene = NULL;

  scene = malloc(sizeof(scene));
  scene->amb_color = 0;
  scene->ambient = 0;
  scene->brightness = 0;
  scene->cam_coord = 0;
  scene->cam_norm = 0;
  scene->fov = 0;
  scene->id = 0;
  scene->light_color = 0;
  scene->light_coord = 0;
  return(scene);
}