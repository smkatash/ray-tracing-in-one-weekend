#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "vector3d.h"


typedef struct s_object t_object;
struct s_object {
    int(*hit)(t_object*, const t_object*, const t_ray*, double, double);
    t_vec3 point;
    t_vec3 normal;
    //void(*setFaceNormal)(t_object*, const t_ray*, const t_vec3*);
    int frontFace;
    double t;
};

inline void Hittable_setFaceNormal(t_object* res, const t_ray* r,
                                   const t_vec3* outwardNormal) {
    res->frontFace = Vec3_dot(&r->dir, outwardNormal) < 0;
    res->normal = *outwardNormal;
    if (!res->frontFace) Vec3_multS(&res->normal, &res->normal, -1);
}

#endif
