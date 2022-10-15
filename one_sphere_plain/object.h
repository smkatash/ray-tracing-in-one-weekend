/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:15:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 15:15:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"

typedef struct s_object t_object;

struct s_object {
    t_vec3 point;
    t_vec3 normal;
    double t;
    int(*hit)(const t_object*, const t_ray*, double, double, t_object*);
    void(*set_face_normal)(t_object*, const t_ray*, const t_vec3*);
    int front;
};

#endif
