#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"
#include "rt.h"
#include "objects.h"

#define MAX_COLOR 255


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

t_camera *set_camera(t_camera *cam, double ratio)
{
    t_vec3  temp;
    t_vec3  temp1;
    double viewport_height = 2.0;
    double viewport_width = ratio * viewport_height;
    double focal_length = 1.0;
    vector_set_each(&cam->origin, 0, 0, 0);
    vector_set_each(&cam->horizontal, viewport_width, 0, 0);
    vector_set_each(&cam->vertical, 0, viewport_height, 0);
    vector_set_each(&cam->focal, 0, 0, focal_length);
    
    vector_divide_t(&temp, &cam->horizontal, 2);
    substraction(&temp1, &cam->origin, &temp);
    vector_divide_t(&temp, &cam->vertical, 2);
    substraction(&cam->lower_left_corner, &temp1, &temp);
    vector_set_each(&temp, 0, 0, focal_length);
    substraction(&cam->lower_left_corner, &cam->lower_left_corner, &temp);
    return (cam);
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

void    put_color(t_vec3 *pixels)
{
	int x = pixels->x * 255.999;
	int y = pixels->y * 255.999;
	int z = pixels->z * 255.999;
	printf("%d %d %d\n", x, y, z);
}

int main() {
    // Image
    const double aspectRatio = 16.0 / 9.0;
    const int imageWidth = 1200;
    const int imageHeight = imageWidth / aspectRatio;
    // World
    t_objectlist* world = randomScene();

    // Camera
    t_camera camera;
    set_camera(&camera, aspectRatio);

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
            put_ray(&r, &camera, u, v);
            ray_color(&curr, &r, (t_object*)world);
            addition(&color, &color, &curr);
            put_color(&color);
        }
    }

    fprintf(stderr, "\nDone.\n");
    return 0;
}
