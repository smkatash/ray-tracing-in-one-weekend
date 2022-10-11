#include "rt.h"
#include "vec3.h"
#include "objects.h"

// Sets res to the position of the ray after traveling in dir for time t.
int ray_at(t_vec3* res, const t_ray* r, double t) {
    vector_multiply_t(res, &r->dir, t);
    addition(res, &r->origin, res);
    return 1;
}

t_color* ray_color(t_color* res, const t_ray* r, const t_object* world) 
{
    t_object record;
    t_color color = (t_color){1, 1, 1};
    if (world->hit(&record, world, r, 0, INFINITY)) 
    {
        addition(&record.normal, &record.normal, &color);
        vector_multiply_t(res, &record.normal, 0.5);
        return res;
    }
    t_vec3 dir;
    norm_vec3(&dir, &r->dir);
    double t = 0.5*(dir.y + 1.0);
    vector_multiply_t(res, &color, (1 - t));
    color = (t_color){0.5, 0.7, 0.7};
    vector_multiply_t(&color, &color, t);
    addition(res, res, &color);
    return res;
}