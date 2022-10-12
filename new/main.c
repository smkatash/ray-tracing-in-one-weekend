/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:43:31 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/13 00:01:31 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "color.h"
#include "ray.h"
#include "object.h"
#include "objectlist.h"
#include "sphere.h"
#include "rt.h"

t_color *ray_color(t_color *color, const t_ray *ray, const t_object* scene, int depth)
{
	t_color		color_temp;
	t_vec3		unit_dir;
	t_vec3		target;
	t_vec3		random;
	t_object	record;;
	double		t;
	double		d;
	
    if (depth <= 0)
        return vector_set_each(color, 0, 0, 0);
	if (scene->hit(scene, ray, 0.001, INFINITY, &record))
	{
		addition(&target, &record.point, random_in_hemisphere(&random, &record.normal));
		vector_set_each((t_vec3 *)&ray->origin, record.point.x, record.point.y, record.point.z);
		substraction((t_vec3 *)&ray->dir, &target, &record.point);
		return (vector_multiply_t(color, ray_color(color, ray, scene, depth - 1), 0.5));
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

t_objectlist* set_scene(void)
{
	t_objectlist* world = ft_listnew();
	t_sphere* plain = malloc(sizeof(t_sphere));
	sphere_init(plain, (t_vec3){0,-100.5, -1}, 100);
	ft_list_pushback(world, (t_object*)plain);

	t_sphere* ball = malloc(sizeof(t_sphere));
	sphere_init(ball, (t_vec3){0, 0, -1}, 0.7);
	ft_list_pushback(world, (t_object*)ball);
	return world;
}

int main(void) 
{
	t_camera		*camera;
	t_color			pxl_color;
	t_color			merged_color;
	t_ray			ray;
	t_objectlist	*scene;
	double			v;
	double			u;
	
	// Image
	const double ratio = 16.0 / 9.0;
	const int width = 400;
	const int height = (int) width / ratio;
	const int samples_per_pixel = 100;
	const int max_depth = 30;


	// Scene
	scene = set_scene();
	// Camera
	camera = malloc(sizeof(t_camera));
	set_camera(camera, ratio);

	// Render
	printf("P3\n%d %d\n255\n", width, height);
	for (int h = height - 1; h >= 0; --h) 
	{
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