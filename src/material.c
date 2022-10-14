/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:48:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 21:27:41 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/material.h"
#include "../include/object.h"
#include "../include/rt.h"

static int scatter_lambertian(t_ray* scattered, const t_ray* ray_in, const t_object* object, t_color* attenuation) 
{
    scattered->origin = object->point;
    random_unit_vector(&scattered->dir);
    addition(&scattered->dir, &scattered->dir, &object->normal);
   // Catch degenerate scatter direction
    if (near_zero(&scattered->dir))
        scattered->dir = object->normal;
    *attenuation = ((t_lambertian*)object->material)->albedo;
    return (1);
}

void* lambertian_init(t_lambertian* lamb_object, t_color albedo)
{
    lamb_object->base.scatter = scatter_lambertian;
    lamb_object->albedo = albedo;
    return (lamb_object);
}

static int scatter_metal(t_ray* scattered, const t_ray* ray_in, const t_object* object, t_color* attenuation) 
{
    t_vec3   fuzz;
    t_vec3   temp;

    scattered->origin = object->point;
    *attenuation = ((t_metal*)object->material)->albedo;
    reflect(&scattered->dir, unit_vector(&temp, &ray_in->dir), &object->normal);
    random_in_unit_sphere(&fuzz);
    vector_multiply_t(&fuzz, &fuzz, ((t_metal*)object->material)->fuzz);
    addition(&scattered->dir, &scattered->dir, &fuzz);
    return (dot_product(&scattered->dir, &object->normal) > 0);
}

void* metal_init(t_metal* metal, t_color albedo, double fuzz) 
{
    metal->base.scatter = scatter_metal;
    metal->albedo = albedo;
    metal->fuzz = fuzz;
    return (metal);
}

// Schlick's approximation for reflectance.
static double reflectance(double cosine, double ref_idx) {
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0*r0;
    return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

static int scatter_dielect(t_ray* scattered, const t_ray* ray_in, const t_object* object, t_color* attenuation)
{
    double  refr_ratio;
    double  cos_theta;
    double  sin_theta;
    t_vec3  unit_dir;
    t_vec3  temp;
    int     no_refract;
    
    vector_set_each(attenuation, 1.0, 1.0, 1.0);
    refr_ratio = object->front ? (1.0 / ((t_dielectric*)object->material)->refract_index) : ((t_dielectric*)object->material)->refract_index;
    unit_vector(&unit_dir, &ray_in->dir);
    vector_multiply_t(&temp, &unit_dir, -1);
    cos_theta = fmin(dot_product(&temp, &object->normal), 1.0);
    sin_theta = sqrt(1.0 - cos_theta * cos_theta);
    no_refract = refr_ratio * sin_theta > 1.0;
    if (no_refract || reflectance(cos_theta, refr_ratio) > random_double())
        reflect(&temp, &unit_dir, &object->normal);
    else
        refract(&temp, &unit_dir, &object->normal, refr_ratio);
    scattered->origin = object->point;
    scattered->dir = temp;
    return (1);
}

void* dielectric_init(t_dielectric* dielect, double refract_index)
{
    dielect->refract_index = refract_index;
    dielect->base.scatter = scatter_dielect;
    return (dielect);
}