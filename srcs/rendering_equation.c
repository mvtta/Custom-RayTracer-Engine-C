/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:18 by user              #+#    #+#             */
/*   Updated: 2022/01/22 22:49:06 by user             ###   ########.fr       */
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
double clamp(double d, double min, double max)
{
  const double t = d < min ? min : d;
  return (t > max ? max : t);
}

double   blinn_phong(t_frame *rt, t_ray *ray, t_obj *obj)
{
    const double shine = 100;
    const double energy_conservation = ((8.0) + shine) / (8.0 * M_PI);
    double spec;
    double difuse;
    double attenuation;
    double camera;
    //double intensity;
    double ratio;
    
    t_vec hit;
    t_vec hit_norm;
    t_vec v;
    t_vec l;
    t_vec lmin;
    t_vec h;

    hit = v_add(&ray->start, &ray->dir);
    hit_norm = v_sub(&hit, obj->obj_coord);
    hit_norm = normalize(&hit_norm);

    v = v_sub(&ray->start, &hit);
    camera = 1 / length(v);
    v = normalize(&v);

    l = v_sub(rt->scene->light_coord, &hit);
    lmin = v_scale(-1.0, &l);
    attenuation = 1 / length(lmin);
    difuse = energy_conservation / MAX(dot_p(&hit_norm, &lmin), 0.0) * camera;
    l = normalize(&l);

    h = v_add(&v, &l);
    h = normalize(&h);

    spec = energy_conservation * (MAX(dot_p(&h, &hit_norm), 0.0));
    ratio = (difuse) + (spec * 0.5 * shine * attenuation);

    printf("spec : %f\n", ratio);
    
    return((ratio));
}

t_color standard_re(t_frame *rt, t_ray *ray, t_obj *obj)
{
        t_color volume;
        double spec = blinn_phong(rt, ray, obj);
        volume = c_grade(rt->scene->light_color, spec, obj->obj_color);
        return(volume);
}