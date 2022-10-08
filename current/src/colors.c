/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:47:16 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/08 17:23:59 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/color.h"

void    put_color(t_vec3 *pixels)
{
	int x = pixels->x * 255.999;
	int y = pixels->y * 255.999;
	int z = pixels->z * 255.999;
	printf("%d %d %d\n", x, y, z);
}

// t_vec3 getRay_at(double t, t_ray *ray)
// {
// 	t_vec3 rayP;
// 	t_vec3 dist;

// 	dist =  multipl_distance(t, &ray->dir);
// 	rayP = addition(&ray->orig, &dist);
// 	return (rayP);
// }

// t_color ray_color(t_ray *ray, t_objects **objLst)
// {
// 	t_intersect rec;
// 	t_color 	ray_color;
// 	t_vec3		unit_dir;
// 	double		t;
// 	double 		d;

// 	if (objectListIntersect(ray, 0, infinity, &rec, objLst))
// 	{
// 		ray_color.r = 0.5 * (1 + rec.normal.x);
// 		ray_color.g = 0.1 * (1 + rec.normal.y);
// 		ray_color.b = 0.5 * (1 + rec.normal.z);
// 		return (ray_color);
// 	}
// 	unit_dir = unit_vector(&ray->dir);
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	d = 1.0 - t;
// 	ray_color.r = (1.0 * d) + (0.2 * t);
// 	ray_color.g = (1.0 * d) + (0.5 * t);
// 	ray_color.b = (1.0 * d) + (1.0 * t);
// 	return (ray_color);
// }