/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:18 by user              #+#    #+#             */
/*   Updated: 2022/01/09 23:51:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtlib.h"

/*
Lo(x, wo) = Le(x, wo) + ∫Ω (BDRF)(LIGHT_AT_INTERSECTION)(LAMBERT), dwi
1.light out from view dir = 2.emissive light + 3.reflected light (view, all dirs)


1. position of stuff (Lo(x, wo))
Lo -> Light that leaved position of stuff
at place(x) and direction wo;

2. light radience in case hot surface.
EMISSIVE
Le -> light emmited at place etc.
Le(x, wo)

3. reflective light
integral withing unit hemisphere omega of the surface normal (preventing more light to be reflected than received
ie. conservation of energy)
and each part:
    3.1 -> BRDF :
    Lr (light radiance) unit solid-angle-in-the-direction-of-a-ray per unit projected-area-perpendicular-to-the-ray
    E  or power per unit surface area
    0i is the angle between wi and surface normal
    i is light incident
    r is reflected light
    PHONG BRDF : brdfPhong = specular_reflectance * pow(dot(R, V), shininess) * LAMBERT;
    . wi Vector 𝑅 is a direction of perfect (mirror) reflection of vector −𝐿 along the normal N
    . wo Vector 𝐿 points toward a light source, or, depending on context, specifies a direction in which
the incident ray reflects
    . n Vector 𝑁 is a shading normal for given surface (possibly coming from a normal map)
    . v Vector 𝑉, the view vector, specifies a direction from shaded point towards the viewer (camera).

    fr(wi, wr) = dLr(wr) / Li(wi)cos0i dwi
    3.2 -> LIGHT_AT_INTERSECTION
    (Li(x,wi))
    3.3 -> LAMBERT
    (wi . n)
    dot(N, L)
    the weakening factor

    To solve the integral of the rendering equation, we use a Monte-Carlo integrator.
    MONTE CARLO INTEGRATION:
        g(t) = f(t)|t1  t0|
    use random sample to make average estimation

*/

t_color standard_re(t_frame *rt, t_ray *ray, t_obj *obj)
{
        float l_lintensity = 0.0;
        float angle;
        t_color volume;

        t_vec hit = v_add(&ray->start, &ray->dir);
        t_vec light = v_add(&hit, rt->scene->light_coord);
        t_vec surface_norm = v_sub(&hit, obj->obj_coord);
        //float shade = (length(hit));
        float bright = (length(light));
        //float bright = length(light);
       // t_vec nd = normalize(&hit);
        angle = MIN(tan(dot_p(&surface_norm, &light)),0);
        l_lintensity = (angle * -1) / (0.2 * bright);
/*         printf("\tANGLE:%f\n", l_lintensity);
        printf("\tBRIGHT:%f\n", bright); */
        //printf("\tANGLE:%f\n \tLINT: %f\n \tLIGHTDIST:%f\n \tSHADE:%f\n", angle, l_lintensity, bright, shade);
        //printf("\tANGLE: %f\n \tLIGHTDIST:%f\n", l_lintensity, bright);

        volume = c_luminance(l_lintensity, obj->obj_color); //* 0.2;
        return(volume);
}