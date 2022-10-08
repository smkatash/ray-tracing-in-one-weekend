#include "../include/ray.h"
#include "../include/vec3.h"
#include "../include/camera.h"

int ray_at(t_vec3* pos, const t_ray* ray, double t) 
{
    vector_multiply_t(pos, &ray->dir, t);
    addition(pos, &ray->origin, pos);
    return 1;
}

t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v)
{
    t_vec3 temp;
    t_vec3 direction;
    
    vector_multiply_t(&temp, &cam->horizontal, u);
    addition(&direction, &cam->lower_left_corner, &temp);
    vector_multiply_t(&temp, &cam->vertical, v);
    addition(&direction, &direction, &temp);
    substraction(&direction, &direction, &cam->origin);
    ray->origin = cam->origin;
    ray->dir = direction;
    return (ray);
}