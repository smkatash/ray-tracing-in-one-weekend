/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:22:43 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 00:53:29 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.h"
#include "ray.h"
#include "object.h"

typedef struct s_object hit_record;
typedef struct s_material t_material;

struct s_material 
{
    int(*scatter)(t_ray*, const t_ray*, const hit_record*, t_color*);
};

typedef struct s_lambertian 
{
    t_material base;
    t_color    *albedo;
} t_lambertian;

t_lambertian* lambertian_init(t_lambertian* lamb_object, t_color albedo);

// typedef struct Metal {
//     Material base;
//     Color albedo;
//     double fuzz;
// } Metal;

// // Initialize a metal material object.
// Metal* Metal_init(Metal* m, Color albedo, double fuzz);

// typedef struct Dielectric {
//     Material base;
//     double ir; // index of refraction
// } Dielectric;

// // Initialize a dielectric material object.
// Dielectric* Dielectric_init(Dielectric* d, double ir);



#endif
