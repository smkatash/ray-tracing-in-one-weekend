#include "../include/vec3.h"
#include "../include/object.h"

static int sphere_hit(t_object *record, const t_object *sphere, const t_ray *ray, double t_min, double t_max)
{
	t_sphere	*obj;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrd;
	double		root;
	t_vec3		outward_normal;

	obj = (t_sphere*)sphere;
	substraction(&oc, &ray->origin, &obj->center);
	a = length_sqrt(&ray->dir);
	half_b = dot_product(&oc, &ray->dir);
	c = length_sqrt(&oc) - (obj->radius * obj->radius);
	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0)
		return (false);
	sqrd = sqrt(discriminant);
	root = (-half_b - sqrd) / a;
	if (root < t_min || root > t_max)
		root = (-half_b + sqrd) / a;
		if (root < t_min || t_max < root)
			return (false);
	record->t = root;
	ray_at(&record->point, ray, record->t);
	substraction(&outward_normal, &record->point, &obj->center);
	vector_divide_t(&outward_normal, &outward_normal, obj->radius);
	norm_vec3(&outward_normal, &outward_normal);
	setFaceNormal(record, ray, &outward_normal);
	return (true);
}


t_sphere* sphere_init(t_sphere* sphere, t_vec3 center, double radius)
{
	sphere->base.hit = sphere_hit;
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}
