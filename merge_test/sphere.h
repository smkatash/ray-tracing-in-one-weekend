#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vector3d.h"

typedef struct s_sphere {
    t_object base;
    t_vec3 center;
    double radius;
} t_sphere;

// Initializes the given sphere.
t_sphere* Sphere_init(t_sphere* s, t_vec3 center, double radius);

#endif
