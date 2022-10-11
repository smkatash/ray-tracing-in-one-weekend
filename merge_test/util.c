#include "util.h"

// snell's law to find refracted vector
t_vec3* Vec3_refract(t_vec3* res, const t_vec3* normalizedIn, 
                   const t_vec3* normalizedNormal, double etaiOverEtat) {
    t_vec3 negIn;
    Vec3_multS(&negIn, normalizedIn, -1);
    double cosTheta = fmin(Vec3_dot(&negIn, normalizedNormal), 1.0);
    t_vec3 resPerp;
    Vec3_multS(&resPerp, 
               Vec3_add(&resPerp, normalizedIn, 
                        Vec3_multS(&resPerp, normalizedNormal, cosTheta)), 
               etaiOverEtat);
    t_vec3 resParallel;
    Vec3_multS(&resParallel,
               normalizedNormal,
               -sqrt(fabs(1.0 - Vec3_magSqr(&resPerp))));
    return Vec3_add(res, &resPerp, &resParallel);
}
