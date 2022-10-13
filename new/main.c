/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:43:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 00:12:29 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "ray.h"
#include "object.h"
#include "objectlist.h"
#include "sphere.h"
#include "rt.h"
#include "material.h"

t_color *ray_color(t_color *color, const t_ray *ray, const t_object* scene, int depth)
{
	t_color		color_temp;
	t_vec3		unit_dir;
	t_object	record;
	t_color		att;
	t_ray		scattered;
	double		t;
	double		d;
	
    if (depth <= 0)
        return (vector_set_each(color, 0, 0, 0));
	if (scene->hit(scene, ray, 0.001, INFINITY, &record))
	{
		if (record.material->scatter(&scattered, ray, scene, &att))
		{
			printf("Here is %fx %fy %fz\n", att.x, att.y, att.z);
			ray_color(color, &scattered, scene, depth - 1);
			return (multiply(color, color, &att));
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
	lambertian_init(mat_ground, (t_color){0.8, 0.8, 0.0});
	t_sphere* plain = malloc(sizeof(t_sphere));
	sphere_init(plain, (t_vec3){0,-100.5, -1}, 100, (t_material*)mat_ground);
	ft_list_pushback(world, (t_object*)plain);
	
	t_lambertian* mat_center = malloc(sizeof(t_lambertian));
	vector_pushback(materials, mat_center);
	lambertian_init(mat_center, (t_color){0.7, 0.3, 0.3});
	t_sphere* ball_center = malloc(sizeof(t_sphere));
	sphere_init(ball_center, (t_vec3){0, 0, -1}, 0.5, (t_material*)mat_center);
	ft_list_pushback(world, (t_object*)ball_center);
	
	t_metal* mat_left = malloc(sizeof(t_metal));
	vector_pushback(materials, mat_left);
	metal_init(mat_left, (t_color){1, 0.8, 0.8});
	t_sphere* ball_left = malloc(sizeof(t_sphere));
	sphere_init(ball_left, (t_vec3){-1, 0, -1}, 0.5, (t_material*)mat_left);
	ft_list_pushback(world, (t_object*)ball_left);
	
	t_metal* mat_right = malloc(sizeof(t_metal));
	vector_pushback(materials, mat_right);
	metal_init(mat_right, (t_color){0.8, 0.6, 1});
	t_sphere* ball_right = malloc(sizeof(t_sphere));
	sphere_init(ball_right, (t_vec3){1, 0, -1}, 0.5, (t_material*)mat_right);
	ft_list_pushback(world, (t_object*)ball_right);
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
	const double ratio = 16.0 / 9.0;
	const int width = 400;
	const int height = (int) width / ratio;
	const int samples_per_pixel = 10;
	const int max_depth = 20;

	// Scene
	materials = vector_new(8, sizeof(t_material*));
	scene = set_scene(materials);
	// Camera
	camera = malloc(sizeof(t_camera));
	set_camera(camera, ratio);

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
	return (0); 
}
