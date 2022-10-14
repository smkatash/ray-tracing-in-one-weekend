/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:18:33 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 00:39:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "material.h"

typedef struct s_sphere {
    t_object    base;
    t_vec3      center;
    double      radius;
    t_material  *material;
} t_sphere;

void* sphere_init(t_sphere* sphere, t_vec3 center, double radius, t_material *material);

#endif