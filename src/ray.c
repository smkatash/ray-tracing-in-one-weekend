/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:46:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 22:08:32 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int ray_at(t_vec3* pos, const t_ray* ray, double t) 
{
	vector_multiply_t(pos, &ray->dir, t);
	addition(pos, &ray->origin, pos);
	return 1;
}

t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v)
{
	t_vec3 temp;
	t_vec3 rd;
	t_vec3 offset;
	
	vector_multiply_t(&rd, random_in_unit_disk(&rd), cam->lens_radius);
	vector_multiply_t(&offset, &cam->u, rd.x);
	vector_multiply_t(&temp, &cam->v, rd.y);
	addition(&offset, &offset, &temp);
	addition(&ray->origin, &cam->origin, &offset);
	
	vector_multiply_t(&temp, &cam->horizontal, u);
	addition(&ray->dir, &cam->lower_left_corner, &temp);
	vector_multiply_t(&temp, &cam->vertical, v);
	addition(&ray->dir, &ray->dir, &temp);
	substraction(&ray->dir, &ray->dir, &ray->origin);
	substraction(&ray->dir, &ray->dir, &offset);
	return (ray);
}
