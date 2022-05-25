/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:18 by user              #+#    #+#             */
/*   Updated: 2022/05/25 13:43:18 by user             ###   ########.fr       */
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
    const double t = d;

    if (t < min)
        return (min);
    if (t > max)
        return (max);
    return (t);
}

int c_range(int d, int min, int max)
{
    const double t = d;

    if (t < min)
        return (min);
    if (t > max)
        return (max);
    return (t);
}

double lambert(t_frame *rt, t_ray *ray, t_obj *obj)
{
    double difuse;
    double att;
    t_vec hit;
    t_vec hit_norm;
    t_vec l;

    hit = v_scale(rt->record.latest_t, ray->dir);
    //hit = v_sub(ray->start, &hit);
    t_vec center = v_sub(ray->start, obj->obj_coord);
    if (obj->id1 == SPHERE)
        hit_norm = v_sub(&hit, &center);
    else
        hit_norm = *obj->obj_norm;
    l = v_sub(rt->scene->l->light_coord, ray->start);
    l = v_add(&l, &hit);
    //att = (length(l));
    att = (1 /length(hit));
    l = normalize(&l);
    hit_norm = normalize(&hit_norm);
    //difuse = c_clamp(dot_p(&hit_norm, &l) + (0.2 / (att)), 0.0, 1.0);
    difuse = c_clamp(dot_p(&hit_norm, &l), 0.0, 1.0) * (att);    
    return ((difuse));
}

double blinn_phong(t_frame *rt, t_ray *ray, t_obj *obj)
{
    float spec;
    double attenuation;
    double total;
    double camera;
    // double ratio;

    t_vec hit;
    t_vec hit_norm;
    t_vec v;
    t_vec l;
    t_vec h;

    hit = v_scale(rt->record.latest_t, ray->dir);
    t_vec center = v_sub(ray->start, obj->obj_coord);
    l = v_sub(rt->scene->l->light_coord, ray->start);
    l = v_add(&l, &hit);
    l = v_scale(1, &l);

    if (obj->id1 == SPHERE)
        hit_norm = v_sub(&hit, &center);
    else
        hit_norm = *obj->obj_norm;
    v = hit;
    v = normalize(&v);
    camera = length(l);
    l = normalize(&l);
    h = v_add(&v, &l);
    attenuation = 1 / camera;
    hit_norm = normalize(&hit_norm);
    h = normalize(&h);
    float dot = dot_p(&h, &hit_norm);
    if (dot < 0 || dot > 1)
        return (0);
    /* 
    shiny specular effect
    */
   spec = pow(dot, 1000) * (attenuation) * 80;
   /*
   brassy metal effect
   */
/* spec = pow(10, dot) * (attenuation); */

/* printf("SPECK:%f | DOT:%f | pow(10, dot):%f | pow(dot, 10):%f\n", spec, dot, pow(10, dot), pow(dot, 10));
    exit(0); */
    total = c_clamp(spec, 0.0, 1);
    return (total);
}

t_color standard_re(t_frame *rt, t_ray *ray, t_obj *obj)
{
    t_color volume;
    double difuse = lambert(rt, ray, obj);
    double shadow = in_shadow(rt, ray, obj);
    double spec = blinn_phong(rt, ray, obj);
    volume = c_new_color(0, 0, 0);
    volume = c_grade(rt, obj, spec, (difuse - shadow));
/*     printf("m1R:%d, m1G:%d, m1B:%d uint:%u \n", volume.r, volume.g, volume.b, volume.hex);
    exit(0); */
    return (volume);
}