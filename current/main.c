/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:20 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/08 18:05:13 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/vec3.h"
#include "include/camera.h"
#include "include/ray.h"
#include "include/color.h"

double infinity = INFINITY;
double  pi = 3.1415926535897932385;


int main(void) 
{
   t_camera  camera;
   t_color   pxl_color;
    t_vec3    origin;
    t_vec3    horizontal;
    t_vec3    vertical;
    t_vec3    focal;
    t_vec3    lower_left_corner;
    double v;
    double  u;
    t_ray   ray;
    t_objects   *world;
    
    // Image
    const double ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int) width / ratio;

    // World
    world = malloc(sizeof(t_objects));
    memset(world, 0, sizeof(t_objects));
    push_back(&world, 0, 0, 1, 0.5);

    // Camera
    set_camera(&camera, ratio);
    // Render
    printf("P3\n%d %d\n255\n", width, height);
    for (int h = height - 1; h >= 0; --h) 
    {
        for (int w = 0; w < width; ++w) 
        {
            u = (double)w / (width - 1);
            v = (double)h / (height - 1);
            ray = put_ray(&origin, &lower_left_corner, &horizontal, &vertical, u, v);
            pxl_color = ray_color(&ray, &world);
            put_color(&pxl_color);
        }
    }
    push_back(&world, 0, -100.5, -10, 100);
    for (int h = height - 1; h >= 0; --h) 
    {
        for (int w = 0; w < width; ++w) 
        {
            u = (double)w / (width - 1);
            v = (double)h / (height - 1);
            ray = put_ray(&origin, &lower_left_corner, &horizontal, &vertical, u, v);
            pxl_color = ray_color(&ray, &world);
            put_color(&pxl_color);
        }
    }
    return (0);
}