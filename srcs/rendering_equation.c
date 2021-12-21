/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:18 by user              #+#    #+#             */
/*   Updated: 2021/12/21 03:11:38 by user             ###   ########.fr       */
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

t_color standard_re(t_frame *rt, t_ray *ray, float t, t_obj *obj)
{
    //static float monte_carlo;
    //t_color black = {0, 0, 0, 0};
    t_vec wo = v_add(rt->scene->light_coord, obj->obj_coord);
    t_vec n = normalize(&wo);
    //t_vec wi = v_sub(&wo, &n);
    t_vec v = v_add(&ray->start, obj->obj_coord);
    if(obj->id1 == PLANE)
    {
        wo = v_add(rt->scene->light_coord, obj->obj_coord);
        v = v_add(&ray->start, obj->obj_coord);
        n = wo;
    }
    v = normalize(&v);
    //float brdf = obj->spec_r * pow(dot_p(&wi, &v), obj->shine);
    float lambert = MAX(dot_p(&n, &v), 0);
    float Lo;
    float Le = 0;
    float Lr = 0.18 * lambert * t;
   /*  float Lr = brdf + lambert + t; */

    /* Lo = MIN(Le + Lr, MAX(monte_carlo, 1)); */
    Lo = Le + Lr;
    printf("\t Lo: %f\n", Lo);
    printf("\t ID: %c\n", obj->id1);
    if(obj->id1 == PLANE)
    {
        //printf("\tright place\n");
        return (c_luminance_plane(Lo, obj->obj_color));
    }
    return (c_blend(Lo, obj->obj_color));

/*     if (Lo == monte_carlo)
        return (black);s
    else
    {
        monte_carlo = Lo;
        return (c_blend(t, Lo, obj->obj_color));
    } */
}