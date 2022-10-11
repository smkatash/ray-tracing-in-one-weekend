#include "camera.h"
#include "ray.h"
#include "vector3d.h"
#include "util.h"

// Initializes a camera object
Camera* Camera_init(Camera* c, t_vec3 lookFrom, t_vec3 lookAt, t_vec3 upVec, 
                    double fovV, double aspectRatio, double aperture, 
                    double focusDist) {
    double viewHeight = 2.0 * tan(degToRad(fovV)/2);
    double viewWidth = viewHeight * aspectRatio;

    Vec3_norm(&c->w, Vec3_sub(&c->w, &lookFrom, &lookAt));
    Vec3_norm(&c->u, Vec3_cross(&c->u, &upVec, &c->w));
    Vec3_cross(&c->v, &c->w, &c->u);

    c->origin = lookFrom;
    Vec3_multS(&c->horizontal, &c->u, viewWidth * focusDist);
    Vec3_multS(&c->vertical, &c->v, viewHeight * focusDist);

    t_vec3 temp;
    Vec3_sub(&c->botLeftCorner, &c->origin, 
             Vec3_multS(&temp, &c->w, focusDist));
    Vec3_sub(&c->botLeftCorner, &c->botLeftCorner, 
             Vec3_divS(&temp, &c->horizontal, 2));
    Vec3_sub(&c->botLeftCorner, &c->botLeftCorner, 
             Vec3_divS(&temp, &c->vertical, 2));
    
    c->lensRadius = aperture / 2;

    return c;
}

// Sets res to the ray pointing from c to (s,t) in view space
t_ray* Camera_getRay(t_ray* res, Camera* c, double s, double t) {
    t_vec3 randomDisk;
    Vec3_randomInUnitDisk(&randomDisk);
    Vec3_multS(&randomDisk, &randomDisk, c->lensRadius);

    t_vec3 tempH, offset;
    Vec3_multS(&tempH, &c->u, randomDisk.x);
    Vec3_multS(&offset, &c->v, randomDisk.y);
    Vec3_add(&offset, &offset, &tempH);

    Vec3_add(&res->origin, &c->origin, &offset);

    t_vec3 scaledH, scaledV;
    Vec3_multS(&scaledH, &c->horizontal, s);
    Vec3_multS(&scaledV, &c->vertical, t);

    // get view coordinates
    Vec3_sub(&res->dir, &c->botLeftCorner, &c->origin);
    Vec3_sub(&res->dir, &res->dir, &offset);
    Vec3_add(&res->dir, &res->dir, &scaledH);
    Vec3_add(&res->dir, &res->dir, &scaledV);
    return res;
}
