/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:59:23 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/14 20:16:20 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/objectlist.h"

static int objectlist_hit(const t_object* sphere, const t_ray* ray, double t_min, double t_max, t_object* record) {
	const t_objectlist* objects;
	t_object temp;
	int hit_point;
	double closest_so_far;
	
	objects = (const t_objectlist*)sphere;
	hit_point = 0;
	closest_so_far = t_max;

	for (size_t i = 0; i < objects->objects->length; i++) 
	{
		t_object* object = (t_object*)vector_at(objects->objects, i);
		if (!object)
			break ;
		if (object->hit(object, ray, t_min, closest_so_far, &temp)) 
		{
			hit_point = 1;
			closest_so_far = temp.t;
			*record = temp;
		}
	}
	return hit_point;
}

t_objectlist* ft_listnew(void)
{
	t_objectlist* objList;

	objList = malloc(sizeof(t_objectlist));
	objList->base.hit = objectlist_hit;
	objList->objects= vector_new(32, sizeof(t_object*));
	return (objList);
}

void ft_listfree(t_objectlist* objList) 
{
	vector_free(objList->objects);
	free(objList);
}

void  ft_list_pushback(t_objectlist* objList, t_object* object) 
{
	vector_pushback(objList->objects, object);
}

void ft_listclear(t_objectlist* objList) 
{
	vector_clear(objList->objects);
}
