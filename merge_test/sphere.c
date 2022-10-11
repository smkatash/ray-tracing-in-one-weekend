#include <math.h>
#include <stdlib.h>

#include "objects.h"
#include "vec3.h"

static inline void setFaceNormal(t_object* sphere, const t_ray* ray, const t_vec3* outwardNormal)
{
    sphere->front = dot_product(&ray->dir, outwardNormal) < 0;
    sphere->normal = *outwardNormal;
    if (!sphere->front) 
        vector_multiply_t(&sphere->normal, &sphere->normal, -1);
}


static int SPHERE_hit(t_object* res, const t_object* hittable, const t_ray* r, 
                      double tMin, double tMax) {
    t_sphere* s = (t_sphere*)hittable;
    t_vec3 oc;
    substraction(&oc, &r->origin, &s->center);
    double a = length_sqrt(&r->dir);
    double halfB = dot_product(&oc, &r->dir);
    double c = length_sqrt(&oc) - (s->radius*s->radius);
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
    substraction(&outwardNormal, &res->point, &s->center);
    vector_divide_t(&outwardNormal, &outwardNormal, s->radius);
    norm_vec3(&outwardNormal, &outwardNormal);
    setFaceNormal(res, r, &outwardNormal);

    return 1;
}

// Initializes the given sphere.
t_sphere* Sphere_init(t_sphere* s, t_vec3 center, double radius) {
    s->base.hit = SPHERE_hit;
    s->center = center;
    s->radius = radius;
    return s;
}
