#include "../include/objectlist.h"
#include <stdbool.h>

static int	hittablelist_hit(t_object *curr_obj, const t_object *sphere, const t_ray *ray, double t_min, double t_max)
{
	const t_objectlist *objectlst;
	t_object			temp;
	int hit_object;
	double	closest_so_far;

	objectlst = (const t_objectlist*)sphere;
	hit_object = false;
	closest_so_far = t_max;

	for (size_t i = 0; i < objectlst->objects->length; i++)
	{
		t_object *obj = (t_object*)vector_at(objectlst->objects, i);
		if (obj->hit(&temp, obj, ray, t_min, closest_so_far))
		{
			hit_object = true;
			closest_so_far = temp.t;
			*curr_obj = temp;
		}
	}
	return (hit_object);
}

t_objectlist *ft_lstnew()
{
	t_objectlist	*obj;
	obj = malloc(sizeof(t_objectlist));
	obj->sphere.hit = hittablelist_hit;
	obj->objects = vector_new(16, sizeof(t_object));
	return (obj);
}

void          ft_lstfree(t_objectlist* objList)
{
	vector_free(objList->objects);
	free(objList);
}

void          push_back(t_objectlist* objList, t_object* object)
{
	vector_pushback(objList->objects, object);
}
void          ft_lstclear(t_objectlist* objList)
{
	vector_clear(objList->objects);
}