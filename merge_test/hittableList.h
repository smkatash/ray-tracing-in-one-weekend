#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "hittable.h"
#include "vector.h"

typedef struct s_objectlist {
    t_object base;
    // stores t_object*
    Vector* objects;
} t_objectlist;

// Returns a malloced hittable list.
t_objectlist* HittableList_new();

// Frees the malloced hittable list.
void HittableList_free(t_objectlist* hittableList);

// Add a hittable to the list.
void HittableList_add(t_objectlist* hittableList, t_object* object);

// Clear the list.
void HittableList_clear(t_objectlist* hittableList);

#endif
