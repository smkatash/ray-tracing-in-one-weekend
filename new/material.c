/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:48:25 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 01:00:14 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

static int scatter_lambertian(t_ray* scattered,  const t_ray* ray_in,
                                   const hit_record* object, t_color* attenuation) 
{
    scattered->origin = object->point;
    random_in_unit_sphere(&scattered->dir);
    addition(&scattered->dir, &scattered->dir, &object->normal);

    if (near_zero(&scattered->dir)) scattered->dir = object->normal;

    *attenuation = &((t_lambertian*)object->material)->albedo;
    return 1;
}

t_lambertian* lambertian_init(t_lambertian* lamb_object, t_color albedo)
{
    lamb_object->base.scatter = &scatter_lambertian;
    lamb_object->albedo = albedo;
    return lamb_object;
}