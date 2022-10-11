/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:46:23 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 13:31:04 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int ray_at(t_vec3* pos, const t_ray* ray, double t) 
{
	vector_multiply_t(pos, &ray->dir, t);
	addition(pos, &ray->origin, pos);
	return 1;
}

t_ray   *put_ray(t_ray  *ray, t_camera *cam, double u, double v)
{
	t_vec3 temp;
	t_vec3 direction;
	
	ray->origin = cam->origin;
	vector_multiply_t(&temp, &cam->horizontal, u);
	addition(&direction, &cam->lower_left_corner, &temp);
	vector_multiply_t(&temp, &cam->vertical, v);
	addition(&direction, &direction, &temp);
	substraction(&direction, &direction, &ray->origin);
	ray->dir = direction;
	return (ray);
}
