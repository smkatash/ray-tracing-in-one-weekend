/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:57:29 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/07 01:27:33 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"

double  hitSphere(t_vec3 *center, double radius, t_ray *ray)
{
	double  x;
	double  half_y;
	double  z;
	double  discriminant;
	t_vec3  oc = substraction(&ray->orig, center);
	x = length_squared(ray->dir.x, ray->dir.y, ray->dir.z);
	half_y = dot(&oc, &ray->dir);
	z = length_squared(oc.x, oc.y, oc.z) - (radius * radius);
	discriminant = (half_y * half_y) - (x * z);
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_y - sqrt(discriminant)) / x);
}

t_sphere	*get_sphere(double x, double y, double z, double radius)
{
	t_sphere *sphere;
	
	sphere = malloc(sizeof(t_sphere));
	sphere->center.x = x;
	sphere->center.y = y;
	sphere->center.z = z;
	sphere->radius = radius;
	return (sphere);
}

t_intersect	*get_object(double x, double y, double z, double radius)
{
	t_intersect	*obj;

	obj = malloc(sizeof(t_intersect));
	obj->sphere = get_sphere(x, y, z, radius);
	return (obj);
}

void	push_back(t_objects **objList, double x, double y, double z, double radius)
{
	t_objects   *current;

	current = *objList;
	if (!current->object)
		current->object = get_object(x, y, z, radius);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->object= get_object(x, y, z, radius);
	}
}

void	initSphere(t_vec3 *center, double *r, t_intersect *inter, t_sphere *sphere)
{
	sphere->center = *center;
	sphere->radius = *r;
	sphere->record = inter;
	inter->sphere = sphere;
}

void	setPlain(t_ray *ray, t_vec3	*out_normal, t_intersect *record)
{
	
	if (dot(&ray->dir, out_normal) > 0.0)
	{
		// ray is inside
		setNegative(out_normal);
		record->normal = *out_normal;
		record->front = false;
	}
	else
	{
		// ray is outside
		record->normal = *out_normal;
		record->front = true;
	}
}

bool  objectIntersect(t_ray *ray, double t_min, double t_max, t_intersect *rec)
{
	double  x;
	double  half_y;
	double  z;
	double  discriminant;
	double  sqrd;
	double  root;
	t_vec3	outwardNormal;
	t_vec3  oc = substraction(&ray->orig, &rec->sphere->center);
	x = length_squared(ray->dir.x, ray->dir.y, ray->dir.z);
	half_y = dot(&oc, &ray->dir);
	z = length_squared(oc.x, oc.y, oc.z) - (rec->sphere->radius * rec->sphere->radius);
	discriminant = (half_y * half_y) - (x * z);
	if (discriminant < 0)
		return (false);
	sqrd = sqrt(discriminant);
	root = (-half_y - sqrd) / x;
	if (root < t_min || t_max < root)
	{
		root = (-half_y + sqrd) / x;
		if (root < t_min || t_max < root)
			return (false);
	}
	rec->t = root;
	rec->point = getRay_at(rec->t, ray);
	outwardNormal = substraction(&rec->point, &rec->sphere->center);
	outwardNormal = division(&outwardNormal, rec->sphere->radius);
	setPlain(ray, &outwardNormal, rec);
	return (true);
}
