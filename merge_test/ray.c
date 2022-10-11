#include "ray.h"
#include "vector3d.h"

// Sets res to the position of the ray after traveling in dir for time t.
int ray_at(t_vec3* res, const t_ray* r, double t) {
    Vec3_multS(res, &r->dir, t);
    Vec3_add(res, &r->origin, res);
    return 1;
}
