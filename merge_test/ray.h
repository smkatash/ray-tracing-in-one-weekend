#ifndef RAY_H
#define RAY_H

#include "vector3d.h"

typedef struct s_ray{
    t_vec3 origin;
    t_vec3 dir;
} t_ray;

// Sets res to the position of the ray after traveling in dir for time t.
int ray_at(t_vec3* res, const t_ray* r, double t);

#endif
