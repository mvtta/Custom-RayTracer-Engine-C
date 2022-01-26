/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:18 by user              #+#    #+#             */
/*   Updated: 2022/01/26 23:57:26 by user             ###   ########.fr       */
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
double c_clamp(double d, double min, double max)
{
    const double t = d < min ? min : d;
    return (t > max ? max : t);
}

double lambert(t_frame *rt, t_ray *ray, t_obj *obj)
{
    double difuse;
    double att;
    t_vec hit;
    t_vec hit_norm;
    t_vec l;

    hit = v_scale(rt->record.latest_t, &ray->dir);
    //hit = v_add(&hit, &ray->start);
    //hit = v_add(&ray->dir, &hit);
  /*   printf("ray.start:%f\n ray.dir:%f\n", ray->start.x, ray->dir.x);
    exit(0); */
    //hit = v_add(rt->record.latest_t, &hit);
    hit_norm = v_sub(&hit, obj->obj_coord);
    //hit_norm = v_sub(&hit_norm, &hit);
    //hit_norm = v_sub(&hit_norm, &hit);
    //hit_norm = v_add(&hit_norm, &hit_norm);
    //hit_norm = v_sub(&hit_norm, &hit_norm);
    //hit_norm = cross_p(hit_norm, hit);
    l = v_sub(&hit, rt->scene->light_coord);
    l = v_scale(1.0, &l);
    //l = v_add(&l, &hit);
    att = length(l);
    l = normalize(&l);
    hit_norm = normalize(&hit_norm);
    printf("\t\nt:%f\n", rt->record.latest_t);
    printf("\t\nh.x:%f\nh.y:%f\nh.z:%f\n", hit.x, hit.y, hit.z);
    printf("\t\nl.x:%f\nl.y:%f\nl.z:%f\n", l.x, l.y, l.z);
    printf("\t\nn.x:%f\nn.y:%f\nn.z:%f\n", hit_norm.x, hit_norm.y, hit_norm.z);

    difuse = dot_p(&hit_norm, &l) * 0.3 * att * 0.5;
    printf("difuse:%f\n", difuse);
    //exit(0);
    //exit(0);
    //exit(0);
   // exit(0);

    return (difuse);
}

/* double blinn_phong(t_frame *rt, t_ray *ray, t_obj *obj)
{
    const double shine = 0.3;
    //const double energy_conservation = ((8.0) + shine) / (8.0 * M_PI);
    double spec;
    double difuse;
    double attenuation;
    double camera;
    // double intensity;
    double ratio;

    t_vec hit;
    t_vec hit_norm;
    t_vec v;
    t_vec l;
    t_vec h;
 
    return ((ratio));
} */

t_color standard_re(t_frame *rt, t_ray *ray, t_obj *obj)
{
    t_color volume;
    //double spec = blinn_phong(rt, ray, obj);
    double difuse = lambert(rt, ray, obj);
    volume = c_grade(rt->scene->light_color, obj->obj_color, 0, difuse);
    return (volume);
}