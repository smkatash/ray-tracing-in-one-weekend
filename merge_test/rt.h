/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:00:47 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/10 17:37:39 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct s_vec3 {
    double x;
    double y;
    double z;
} t_vec3;


typedef struct s_ray {
    t_vec3 origin;
    t_vec3 dir;
} t_ray;

typedef struct s_object t_object;

struct s_object 
{
    int front;
    double t;
    int(*hit)(t_object*, const t_object*, const t_ray*, double, double);
    t_vec3 point;
    t_vec3 normal;
};

typedef struct s_sphere 
{
    double      radius;
    t_vec3      center;
    t_object    base;
} t_sphere;

typedef t_vec3 t_color;
extern double infinity;

typedef struct s_vector {
   void** array;
   size_t length;
   size_t width;
   size_t size;
} t_vector;

typedef struct s_objectlist {
	t_object    sphere;
	t_vector    *objects;
} t_objectlist;

typedef struct s_camera {
    t_vec3 origin;
    t_vec3 horizontal;
    t_vec3 vertical;
    t_vec3 lower_left_corner;
    t_vec3 focal;
}   t_camera;


#endif 