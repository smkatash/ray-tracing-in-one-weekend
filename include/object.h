/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:15:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 21:24:52 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"
#include "material.h"

typedef struct s_object t_object;
typedef struct s_material t_material;

struct s_object {
    t_vec3 point;
    t_vec3 normal;
    double t;
    int(*hit)(const t_object*, const t_ray*, double, double, t_object*);
    void(*set_face_normal)(t_object*, const t_ray*, const t_vec3*);
    int front;
    t_material *material;
};
inline void set_face_normal(t_object* object, const t_ray* r, const t_vec3* outwardNormal) 
{
    // ray is inside the sphere or outside
	object->front = dot_product(&r->dir, outwardNormal) < 0;
	object->normal = *outwardNormal;
	if (!object->front) 
		vector_multiply_t(&object->normal, &object->normal, -1);
}

#endif
