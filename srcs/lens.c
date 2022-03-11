/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/02/13 22:12:43 by user              #+#    #+#             */
/*   Updated: 2022/02/13 23:06:20 by user             ###   ########.fr       */
=======
/*   Created: 2022/02/19 13:45:34 by user              #+#    #+#             */
/*   Updated: 2022/02/24 15:02:54 by user             ###   ########.fr       */
>>>>>>> normed
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

<<<<<<< HEAD
=======
float gaussian_blur();

>>>>>>> normed
float get_focal_len(float fov)
{
    float fl;
    float half = fov / 2;
    fl = (half / (atanf(half)));
<<<<<<< HEAD
    return((fl));
}
=======
    return((fl * 2));
}

/* void  out_of_focus(t_ray *prime)
{
    prime->dir = sin;
} */
>>>>>>> normed
