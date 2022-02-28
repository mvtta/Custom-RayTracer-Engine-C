/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:02:31 by mvaldeta          #+#    #+#             */
/*   Updated: 2022/02/28 19:33:11 by mvaldeta         ###   ########.fr       */
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

  return (blur);
}

unsigned int apply_blur(t_frame *rt, int x, int y)
{
  t_boxblur k;
  //size_t offset;
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

  //printf("x:%d & y:%d\n", x, y);

  k = gaussian_var(x, y);
  //exit(0);

/*   printf("00-> kx:%d & ky:%d \n", k.m_00.x, k.m_00.y);
  printf("01-> kx:%d & ky:%d \n", k.m_01.x, k.m_01.y); */
  //offset = ((y * rt->obj_img.line_length + x * rt->obj_img.bits_per_pixel / 8) / 4);
  //printf("offset:%zu \n", offset);

  gb_1 = ((k.m_00.y * rt->obj_img.line_length) + (k.m_00.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_2 = ((k.m_01.y * rt->obj_img.line_length) + (k.m_01.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_3 = ((k.m_02.y * rt->obj_img.line_length) + (k.m_02.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_4 = ((k.m_10.y * rt->obj_img.line_length) + (k.m_10.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_5 = ((k.m_11.y * rt->obj_img.line_length) + (k.m_11.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_6 = ((k.m_12.y * rt->obj_img.line_length) + (k.m_12.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_7 = ((k.m_20.y * rt->obj_img.line_length) + (k.m_20.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_8 = ((k.m_21.y * rt->obj_img.line_length) + (k.m_21.x * rt->obj_img.bits_per_pixel) / 8) / 4;
  gb_9 = ((k.m_22.y * rt->obj_img.line_length) + (k.m_22.x * rt->obj_img.bits_per_pixel) / 8) / 4;

/*   printf("\t\tGB1:%d\n", gb_1);
  printf("\t\tGB2:%d\n", gb_2);
  printf("\t\tGB3:%d\n", gb_3);
  printf("\t\tGB4:%d\n", gb_4);
  printf("\t\tGB5:%d\n", gb_5);
  printf("\t\tGB6:%d\n", gb_6);
  printf("\t\tGB7:%d\n", gb_7);
  printf("\t\tGB8:%d\n", gb_8);
  printf("\t\tGB9:%d\n", gb_9); */

  sum = gb_1 + gb_2 + gb_3 + gb_4 + gb_5 + gb_6 + gb_7 + gb_8 + gb_9;
  //printf("\tsum_B:%u\n", sum);
  sum /= 9;
  //printf("\t__colorTHERE %u\n", rt->obj_img.data[sum]);
  //exit(0);
  return (rt->obj_img.data[sum]);
}