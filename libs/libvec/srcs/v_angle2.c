/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_angle2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:35:34 by user              #+#    #+#             */
/*   Updated: 2022/05/02 14:35:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double angle_bet_vs(t_vec *v1, t_vec *v2)
{
    float scalar = dot_p(v1, v2);
    float mag1 = length(*v1);
    float mag2 = length(*v2);
    float angle = scalar / (mag1 * mag2);
    // printf("angle should be between 0 & 180: %f\n", acos(angle));
    return (acos(angle));
}