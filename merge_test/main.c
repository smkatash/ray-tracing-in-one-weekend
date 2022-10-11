#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "color.h"
#include "hittable.h"
#include "hittableList.h"
#include "ray.h"
#include "sphere.h"
#include "util.h"
#include "vector3d.h"

#define MAX_COLOR 255

t_color* Ray_color(t_color* res, const t_ray* r, const t_object* world) 
{
    t_object record;
    t_color color = (t_color){1, 1, 1};
    if (world->hit(&record, world, r, 0, INFINITY)) 
    {
        Vec3_add(&record.normal, &record.normal, &color);
        Vec3_multS(res, &record.normal, 0.5);
        return res;
    }
    t_vec3 dir;
    Vec3_norm(&dir, &r->dir);
    double t = 0.5*(dir.y + 1.0);
    Vec3_multS(res, &color, (1 - t));
    color = (t_color){0.5, 0.7, 0.7};
    Vec3_multS(&color, &color, t);
    Vec3_add(res, res, &color);
    return res;
}

t_objectlist* randomScene() {
    t_objectlist* world = HittableList_new();

    t_sphere* ground = malloc(sizeof *ground);
    Sphere_init(ground, (t_vec3){0,-100.5, -1}, 100);
    HittableList_add(world, (t_object*)ground);

    t_sphere* s3 = malloc(sizeof *s3);
    Sphere_init(s3, (t_vec3){2, 0, 0}, 0.5);
    HittableList_add(world, (t_object*)s3);
    return world;
}

int main() {
    // Image
    const double aspectRatio = 16.0 / 9.0;
    const int imageWidth = 1200;
    const int imageHeight = imageWidth / aspectRatio;
    // World
    t_objectlist* world = randomScene();

    // Camera
    Camera camera;
    t_vec3 lookFrom = {10,2,3}, lookAt = {0,0,0}, temp;
    Vec3_sub(&temp, &lookAt, &lookFrom);
    double focusDist = 10;
    Camera_init(&camera, lookFrom, lookAt, (t_vec3){0,1,0}, 20, aspectRatio, 0.1,
                focusDist);

    // Render
    printf("P3\n%i %i\n%i\n", imageWidth, imageHeight, MAX_COLOR);

    double u, v;
    t_ray r;
    t_color color, curr;
    for (int i = imageHeight-1; i >= 0; i--) {
        fprintf(stderr, "Rows remaining: %5i\r", i);
        fflush(stderr);
        for (int j = 0; j < imageWidth; j++) {
            color = (t_color){0,0,0};
            u = (double)j / (imageWidth - 1);
            v = (double)i / (imageHeight - 1);
            Camera_getRay(&r, &camera, u, v);
            Ray_color(&curr, &r, (t_object*)world);
            Vec3_add(&color, &color, &curr);
            Color_fprintln(stdout, &color);
        }
    }

    fprintf(stderr, "\nDone.\n");
    return 0;
}
