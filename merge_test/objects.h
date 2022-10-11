#ifndef OBJECTS_H
# define OBJECTS_H

#include "rt.h"

t_objectlist* HittableList_new();
void HittableList_free(t_objectlist* hl);
void HittableList_add(t_objectlist* hittableList, t_object* object);
void HittableList_clear(t_objectlist* hittableList);

t_sphere* Sphere_init(t_sphere* s, t_vec3 center, double radius);

t_color* ray_color(t_color* res, const t_ray* r, const t_object* world);
int      ray_at(t_vec3* res, const t_ray* r, double t);

#endif