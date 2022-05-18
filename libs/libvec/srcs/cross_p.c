/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:17:47 by user              #+#    #+#             */
/*   Updated: 2022/05/01 23:18:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libvec.h"

t_vec cross_p(t_vec a, t_vec b)
{
    t_vec cross;

    cross.x = a.x * b.z - a.z * b.y;
    cross.y = a.z * b.x - a.x * b.z;
    cross.z = a.x * b.y - a.y * b.x;

    return (cross);
}