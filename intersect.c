/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:42:57 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/05/14 22:54:46 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"
#include "math.h"



float scene_hit(t_ray ray, t_hit* hit, t_sphere sphere) 
{
    float t = 0;
    float lastt = 9999;
    float result = -1;

        t = intersection(ray, sphere);
        if (t > 0 && t < lastt)
		{
            result = t;
            hit->sphere = &sphere;
        }
        

    hit->t = result;
    return(result);
}

float intersection(t_ray ray, t_sphere sphere) 
{
    /* Compute discriminate
    (d . (e - c))^2 - (d.d) * ((e-c).(e-c) - r^2) */
    t_vec eminusc = minus_v(ray.origin, sphere.c);
    float d2 = dot(ray.direction, ray.direction);
    float discriminate = dot(ray.direction, eminusc);
    discriminate *= discriminate;
    discriminate -= (d2 * (dot(eminusc, eminusc) - pow(sphere.r, 2.0)));

    if (discriminate >= 0)
	{
        /* Solve quadratic for t
        t = -d . (e-c) +- discriminate / d.d */
        float t = dot(scale_v(-1, ray.direction), eminusc);
        float t1 = (t + sqrt(discriminate)) / d2;
        float t2 = (t - sqrt(discriminate)) / d2;

        if (t1 > 0 && t2 > 0)
		{
            if (t1 < t2)
                return (t1);
			else 
                return (t2);
        } 
		else if (t1 > 0)
            return (t1);
		else if (t2 > 0)
            return (t2);
		else
            return (-1);
    }
	else 
        return (-1);
}