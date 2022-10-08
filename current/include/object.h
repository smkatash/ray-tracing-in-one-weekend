#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"
#include "vec3.h"
#include <stdbool.h>

typedef struct s_object 
{
    int(*hit)(t_object*, const t_object*, const t_ray*, double, double);
    int front;
    double t;
    t_vec3 point;
    t_vec3 normal;
    void(*setFaceNormal)(t_object*, const t_ray*, const t_vec3*);
} t_object;

typedef struct s_sphere 
{
    double      radius;
    t_vec3      center;
    t_object    base;
} t_sphere;

inline void setFaceNormal(t_object* sphere, const t_ray* ray, const t_vec3* outwardNormal)
{
    sphere->front = dot_product(&ray->dir, outwardNormal) < 0;
    sphere->normal = *outwardNormal;
    if (!sphere->front) 
        vector_multiply_t(&sphere->normal, &sphere->normal, -1);
}

t_sphere* sphere_init(t_sphere* sphere, t_vec3 center, double radius);

#endif