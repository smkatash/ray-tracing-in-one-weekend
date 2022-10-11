#include <math.h>
#include <stdlib.h>

#include "sphere.h"

static int SPHERE_hit(t_object* res, const t_object* hittable, const t_ray* r, 
                      double tMin, double tMax) {
    t_sphere* s = (t_sphere*)hittable;
    t_vec3 oc;
    Vec3_sub(&oc, &r->origin, &s->center);
    double a = Vec3_magSqr(&r->dir);
    double halfB = Vec3_dot(&oc, &r->dir);
    double c = Vec3_magSqr(&oc) - (s->radius*s->radius);
    double discriminant = (halfB*halfB - a*c);
    if (discriminant < 0) return 0;

    // Find nearest root in the given range
    double sqrtD = sqrt(discriminant);
    double root = (-halfB - sqrtD) / a;
    if (root < tMin || root > tMax) {
        root = (-halfB + sqrtD) / a;
        if (root < tMin || root > tMax) return 0;
    }

    // Set hitrecord
    res->t = root;
    ray_at(&res->point, r, res->t);
    t_vec3 outwardNormal;
    Vec3_sub(&outwardNormal, &res->point, &s->center);
    Vec3_divS(&outwardNormal, &outwardNormal, s->radius);
    Vec3_norm(&outwardNormal, &outwardNormal);
    Hittable_setFaceNormal(res, r, &outwardNormal);

    return 1;
}

// Initializes the given sphere.
t_sphere* Sphere_init(t_sphere* s, t_vec3 center, double radius) {
    s->base.hit = &SPHERE_hit;
    s->center = center;
    s->radius = radius;
    return s;
}
