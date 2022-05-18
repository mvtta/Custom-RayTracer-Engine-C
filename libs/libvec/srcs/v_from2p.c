/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_from2p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:35:43 by user              #+#    #+#             */
/*   Updated: 2022/05/02 14:35:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec v_from_2p(t_vec start, t_vec end)
{
    t_vec vector;
    vector = v_sub(&end, &start);
    vector.x = sqrtf(vector.x * vector.x);
    vector.y = sqrtf(vector.y * vector.y);
    vector.z = sqrtf(vector.z * vector.z);
    return (vector);
}