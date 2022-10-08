#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_ray {
    t_vec3 origin;
    t_vec3 dir;
} t_ray;

int     ray_at(t_vec3* pos, const t_ray* ray, double t);
t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v);

#endif