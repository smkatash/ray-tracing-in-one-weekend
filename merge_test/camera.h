#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vector3d.h"

typedef struct Camera {
    t_vec3 origin;
    t_vec3 botLeftCorner;
    t_vec3 horizontal;
    t_vec3 vertical;
    t_vec3 u, v, w;
    double lensRadius;
} Camera;

// Initializes a camera object
Camera* Camera_init(Camera* c, t_vec3 lookFrom, t_vec3 lookAt, t_vec3 upVec, 
                    double fovV, double aspectRatio, double aperture, 
                    double focusDist);

// Sets res the the ray pointing from c to (u,v) in view space
t_ray* Camera_getRay(t_ray* res, Camera* c, double u, double v);

#endif
