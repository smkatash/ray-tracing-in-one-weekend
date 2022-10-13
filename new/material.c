/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:48:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 17:21:34 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "object.h"
#include "rt.h"

static int scatter_lambertian(t_ray* scattered, const t_ray* ray_in, const t_object* object, t_color* attenuation) 
{
    scattered->origin = object->point;
    random_unit_vector(&scattered->dir);
    addition(&scattered->dir, &scattered->dir, &object->normal);
    if (near_zero(&scattered->dir))
        scattered->dir = object->normal;
    *attenuation = ((t_lambertian*)object->material)->albedo;
    return (1);
}

void* lambertian_init(t_lambertian* lamb_object, t_color albedo)
{
    lamb_object->albedo = albedo;
    lamb_object->base.scatter = scatter_lambertian;
    return (lamb_object);
}

static int scatter_metal(t_ray* scattered, const t_ray* ray_in, const t_object* object, t_color* attenuation) 
{
    scattered->origin = object->point;
    reflect(&scattered->dir, unit_vector(&scattered->dir, &ray_in->dir), &object->normal);
    printf("Albedo %f %f %f\n", ((t_metal*)object->material)->albedo.x,  ((t_metal*)object->material)->albedo.y, ((t_metal*)object->material)->albedo.z);
    printf("Atten %p \n",attenuation);
    fflush(stdout);
    *attenuation = ((t_metal*)object->material)->albedo;
    return (dot_product(&scattered->dir, &object->normal) > 0);
}

void* metal_init(t_metal* metal, t_color albedo) 
{
    metal->albedo = albedo;
    metal->base.scatter = scatter_metal;
    return (metal);
}