/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:22:43 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 17:01:43 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "object.h"

typedef struct s_material t_material;
typedef struct s_object t_object;

struct s_material 
{
    int(*scatter)(t_ray*, const t_ray*, const t_object*, t_color*);
};

typedef struct s_lambertian 
{
    t_material base;
    t_color    albedo;
} t_lambertian;

typedef struct s_metal {
    t_material  base;
    t_color     albedo;
} t_metal;

void* lambertian_init(t_lambertian* lamb_object, t_color albedo);
void* metal_init(t_metal* metal, t_color albedo);

// typedef struct Dielectric {
//     Material base;
//     double ir; // index of refraction
// } Dielectric;

// // Initialize a dielectric material object.
// Dielectric* Dielectric_init(Dielectric* d, double ir);


#endif
