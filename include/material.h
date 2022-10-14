/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:22:43 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 22:31:58 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "object.h"

typedef struct s_material t_material;
typedef struct s_object t_object;

// Type Material: 
// 1. Produces a scattered ray (or it absorbed the incident ray).
// 2. If scattered, define how much the ray should be attenuated.

struct s_material 
{
    int(*scatter)(t_ray*, const t_ray*, const t_object*, t_color*);
};


// Lambertian (diffuse): 
// It can either scatter always and attenuate by its reflectance 𝑅, 
// or it can scatter with no attenuation but absorb the fraction 1−𝑅 
// of the rays, or it could be a mixture of those strategies. 
typedef struct s_lambertian 
{
    t_material base;
    t_color    albedo;
} t_lambertian;

// Metal (mirrored light reflection):
// The reflected ray direction is 𝐯+2𝐛. 𝐧 is a unit vector, but 𝐯 may not be. 
// The length of 𝐛 should be 𝐯⋅𝐧. 𝐯 points in, we will need a minus sign, yielding:
// v - 2*dot(v,n)*n;
typedef struct s_metal {
    t_material  base;
    t_color     albedo;
    double      fuzz;
} t_metal;

// Dielectrics (refraction):
// The refraction is described by Snell’s law:
// 𝜂⋅sin𝜃=𝜂′⋅sin𝜃′
typedef struct t_dielectric {
    t_material base;
    double  refract_index;
} t_dielectric;

void* lambertian_init(t_lambertian* lamb_object, t_color albedo);
void* metal_init(t_metal* metal, t_color albedo, double fuzz);
void* dielectric_init(t_dielectric* dielect, double refract_index);

#endif
