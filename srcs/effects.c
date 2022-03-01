/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/03/01 18:30:36 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

int limit_kernel(t_frame *rt, float source, float deviation, char xy)
{
  int limit;

  if (xy == 'x')
    limit = rt->window_w - 1;
  if (xy == 'y')
    limit = rt->window_h - 1;
  if (deviation > limit)
    return (limit);
  if (deviation < 0)
    return (source);
  return (deviation);
}

t_boxblur gaussian_var(int x, int y)
{
  t_boxblur blur;
  int n_x[] = {-1, 0, 1};
  int n_y[] = {-1, 0, 1};

  /* first col */
  //printf("REF-> ox:%d & oy:%d \n", x, y);
  blur.m_00.x = x + n_x[0];
  blur.m_00.y = y + n_y[0];
  //printf("00-> x:%d & y:%d \n", blur.m_00.x, blur.m_00.y);

  blur.m_01.x = x + n_x[0];
  blur.m_01.y = y + n_y[1];
  //printf("01-> x:%d & y:%d \n", blur.m_01.x, blur.m_01.y);

  blur.m_02.x = x + n_x[0];
  blur.m_02.y = y + n_x[2];
  //printf("02-> x:%d & y:%d \n", blur.m_02.x, blur.m_02.y);

  /* second col */
  blur.m_10.x = x + n_x[1];
  blur.m_10.y = y + n_y[0];
  //printf("10-> x:%d & y:%d \n", blur.m_10.x, blur.m_10.y);

  blur.m_11.y = y + n_y[1];
  blur.m_11.x = x + n_x[1];
  //printf("10-> x:%d & y:%d \n", blur.m_11.x, blur.m_11.y);

  blur.m_12.x = x + n_x[1];
  blur.m_12.y = y + n_x[2];
  //printf("10-> x:%d & y:%d \n", blur.m_12.x, blur.m_12.y);
  /* third col */
  blur.m_20.x = x + n_x[2];
  blur.m_20.y = y + n_y[0];
  //printf("20-> x:%d & y:%d \n", blur.m_20.x, blur.m_20.y);

  blur.m_21.x = x + n_x[2];
  blur.m_21.y = y + n_y[1];
  //printf("21-> x:%d & y:%d \n", blur.m_21.x, blur.m_21.y);

  blur.m_22.x = x + n_x[2];
  blur.m_22.y = y + n_x[2];
  //printf("22-> x:%d & y:%d \n", blur.m_22.x, blur.m_22.y);
  //exit(0);
  return (blur);
}

void  depth_map(t_frame *rt, int x, int y, unsigned int pixel_color)
{
    rt->pixel_map.map[x][rt->window_h - y] = pixel_color;
}

unsigned int apply_blur(t_frame *rt, int x, int y)
{
  t_boxblur k;

  unsigned int sum;
  unsigned int gb_1;
  unsigned int gb_2;
  unsigned int gb_3;
  unsigned int gb_4;
  unsigned int gb_5;
  unsigned int gb_6;
  unsigned int gb_7;
  unsigned int gb_8;
  unsigned int gb_9;


  k = gaussian_var(x, y);

  gb_1 = rt->pixel_map.map[x - 1][y - 1];
  gb_2 = rt->pixel_map.map[x - 1][y - 0];
  gb_3 = rt->pixel_map.map[x - 1][y + 1];
  gb_4 = rt->pixel_map.map[x - 0][y - 1];
  gb_5 = rt->pixel_map.map[x - 0][y - 0];
  gb_6 = rt->pixel_map.map[x - 0][y + 1];
  gb_7 = rt->pixel_map.map[x + 1][y - 1];
  gb_8 = rt->pixel_map.map[x + 1][y - 0];
  gb_9 = rt->pixel_map.map[x + 1][y + 1];
  
  printf("%u\n%u\n%u\n%u\n%u\n%u\n%u\n%u\n%u\n\n", gb_1, gb_2, gb_3, gb_4, gb_5, gb_6, gb_7, gb_8, gb_9);
  //exit(0);
  sum = gb_1 + gb_2 + gb_3 + gb_4 + gb_5 + gb_6 + gb_7 + gb_8 + gb_9;
  sum /= 9;
  depth_map(rt, x, y, sum);
  return (sum);
}