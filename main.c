/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:43:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/15 00:25:37 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/camera.h"
#include "include/color.h"
#include "include/ray.h"
#include "include/object.h"
#include "include/objectlist.h"
#include "include/sphere.h"
#include "include/rt.h"
#include "include/material.h"

// (1) calculate the ray from the eye to the pixel, 
// (2) determine which objects the ray intersects, and 
// (3) compute a color for that intersection point.
t_color *ray_color(t_color *color, const t_ray *ray, const t_object* scene, int depth)
{
	t_color		color_temp;
	t_vec3		unit_dir;
	t_object	record;
	t_color		att;
	t_color		temp;
	t_ray		scattered;
	double		t;
	double		d;
	
    // If the ray bounce limit is exceeded, no more light is gathered.
	if (depth <= 0)
        return (vector_set_each(color, 0, 0, 0));
	// Calculating reflected ray origins with tolerance
	// Ignore hits very near zero. 
	if (scene->hit(scene, ray, 0.001, INFINITY, &record))
	{
		if (record.material->scatter(&scattered, ray, &record, &att))
		{
			return (multiply(color, &att, ray_color(&temp, &scattered, scene, depth - 1)));
		}
		return (vector_set_each(color, 0, 0, 0));
	}
	unit_vector(&unit_dir, &ray->dir);
	t = 0.5 * (unit_dir.y + 1.0);
	d = 1.0 - t;
	vector_set_each(&color_temp, 1.0, 1.0, 1.0);
	vector_multiply_t(color, &color_temp, d);
	vector_set_each(&color_temp, 0.5, 0.7, 1.0);
	vector_multiply_t(&color_temp, &color_temp, t);
	addition(color, color, &color_temp);
	return (color);
}

t_objectlist* set_scene(t_vector *materials)
{
	t_objectlist* world = ft_listnew();

	t_lambertian* mat_ground = malloc(sizeof(t_lambertian));
	vector_pushback(materials, mat_ground);
	lambertian_init(mat_ground, (t_color){0.5, 0.5, 0.5});
	t_sphere* plain = malloc(sizeof(t_sphere));
	sphere_init(plain, (t_vec3){0,-1000, -1}, 1000, (t_material*)mat_ground);
	ft_list_pushback(world, (t_object*)plain);

	t_vec3 point = {4,0.2,0};
	t_vec3 point1;
	t_vec3 temp;
	t_vec3	temp1;
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            t_vec3 center = {a + 0.9 * random_double(), 0.2, b + 0.9 * random_double()};
            substraction(&point1, &center, &point);
            if (length_sqrt(&point) > 0.9) 
			{
                double choose_mat = random_double();
                if (choose_mat < 0.8) 
				{
                    // diffuse
                    random_minmax_vector(&temp, 0, 1);
                    random_minmax_vector(&temp1, 0, 1);
                    multiply(&temp, &temp, &temp1);
                    t_lambertian* diffused = malloc(sizeof(t_lambertian));
                    vector_pushback(materials, diffused);
                    lambertian_init(diffused, temp);
                    t_sphere* ball_mat = malloc(sizeof(t_sphere));
                    sphere_init(ball_mat, center, 0.2, (t_material*)diffused);
                    ft_list_pushback(world, (t_object*)ball_mat);
                } 
				else if (choose_mat < 0.95) 
				{
                    // metal
                    random_minmax_vector(&temp, 0.5, 1);
                    t_metal* metallic = malloc(sizeof(t_metal));
                    vector_pushback(materials, metallic);
                    metal_init(metallic, temp, random_double());
                    t_sphere* ball_metal = malloc(sizeof(t_sphere));
                    sphere_init(ball_metal, center, 0.2, (t_material*)metallic);
                    ft_list_pushback(world, (t_object*)ball_metal);
                } 
				else 
				{
                    // glass
                    t_dielectric* dielectric = malloc(sizeof(t_dielectric));
                    vector_pushback(materials, dielectric);
                    dielectric_init(dielectric, 1.5);
                    t_sphere* ball_diel = malloc(sizeof(t_sphere));
                    sphere_init(ball_diel, center, 0.2, (t_material*)dielectric);
                    ft_list_pushback(world, (t_object*)ball_diel);
                }
            }
        }
    }

	t_dielectric* material1 = malloc(sizeof(t_dielectric));
	vector_pushback(materials, material1);
	dielectric_init(material1, 1.5);
	t_sphere* ball1 = malloc(sizeof(t_sphere));
	sphere_init(ball1, (t_vec3){0, 1, 0}, 1.0, (t_material*)material1);
	ft_list_pushback(world, (t_object*)ball1);
	
	t_lambertian* material2 = malloc(sizeof(t_lambertian));
	vector_pushback(materials, material2);
	lambertian_init(material2,(t_color){0.4, 0.2, 0.1});
	t_sphere* ball2 = malloc(sizeof(t_sphere));
	sphere_init(ball2, (t_vec3){-4, 1, 0}, 1.0, (t_material*)material2);
	ft_list_pushback(world, (t_object*)ball2);
	
	t_metal* material3 = malloc(sizeof(t_metal));
	vector_pushback(materials, material3);
	metal_init(material3, (t_color){0.7, 0.6, 0.5}, 0.0);
	t_sphere* ball3 = malloc(sizeof(t_sphere));
	sphere_init(ball3, (t_vec3){4, 1, 0}, 1.0, (t_material*)material3);
	ft_list_pushback(world, (t_object*)ball3);
	return (world);
}

int main(void) 
{
	t_camera		*camera;
	t_color			pxl_color;
	t_color			merged_color;
	t_ray			ray;
	t_objectlist	*scene;
	t_vector		*materials;
	double			v;
	double			u;
	
	// Image
	const double ratio = 3.0 / 2.0;
	const int width = 1200;
	const int height = (int) width / ratio;
	// Applying multi-sampled pixels
	const int samples_per_pixel = 500;
	// Limit the maximum recursion depth
	const int max_depth = 50;

	// Scene
	materials = vector_new(8, sizeof(t_material*));
	scene = set_scene(materials);
	// Camera
	camera = malloc(sizeof(t_camera));
	set_camera(camera, ratio, 20);
	// Render
	printf("P3\n%d %d\n255\n", width, height);
	for (int h = height - 1; h >= 0; --h) 
	{
		fprintf(stderr, "\rScanlines remaining: %5i\r", h);
        fflush(stderr);
		for (int w = 0; w < width; ++w) 
		{
			vector_set_each(&merged_color, 0, 0, 0);
			for (int pxl = 0; pxl < samples_per_pixel; ++pxl) 
			{
				u = (double)(w + random_double()) / (width - 1);
				v = (double)(h + random_double()) / (height - 1);
				put_ray(&ray, camera, u, v);
				ray_color(&pxl_color, &ray, (t_object*)scene, max_depth);
				addition(&merged_color, &merged_color, &pxl_color);
			}
			put_color(&merged_color, samples_per_pixel);
		}
	}
	// does not free memory completely. wip
	free(camera);
	vector_free(materials);
	ft_listfree(scene);
	return (0); 
}
