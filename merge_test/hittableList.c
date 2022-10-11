#include <stdlib.h>

#include "hittableList.h"

// For a given ray, set hittable to the closest object hit.
// Returns 1 if an object was hit.
// Otherwise, returns 0;
static int HITTABLELIST_hit(t_object* res, const t_object* hittable,  
                     const t_ray* r, double tMin, double tMax) {
    const t_objectlist* hittableList = (const t_objectlist*)hittable;
    t_object temp;
    int hitAnything = 0;
    double closestSoFar = tMax;

    for (size_t i = 0; i < hittableList->objects->length; i++) {
        t_object* object = (t_object*)Vector_at(hittableList->objects, i);
        if (object->hit(&temp, object, r, tMin, closestSoFar)) {
            hitAnything = 1;
            closestSoFar = temp.t;
            *res = temp;
        }
    }

    return hitAnything;
}

t_objectlist* HittableList_new() {
    t_objectlist* hl = malloc(sizeof *hl);
    hl->base.hit = HITTABLELIST_hit;
    hl->objects= Vector_new(16, sizeof(t_object*));
    return hl;
}

void HittableList_free(t_objectlist* hl) {
    Vector_free(hl->objects);
    free(hl);
}

// Add a hittable to the list.
void HittableList_add(t_objectlist* hittableList, t_object* object) {
    Vector_push(hittableList->objects, object);
}

// Clear the list.
void HittableList_clear(t_objectlist* hittableList) {
    Vector_clear(hittableList->objects);
}
