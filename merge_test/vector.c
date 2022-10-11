#include <stdlib.h>

#include "vector.h"

// Returns a malloced vector with the given size.
Vector* Vector_new(size_t size, size_t width) {
    Vector* v = malloc(sizeof *v);
    if (v == NULL) return NULL;

    v->length = 0;
    v->width = width;
    v->size = size;
    v->array = malloc(v->size * v->width);
    return v;
}

// Frees the vector.
void Vector_free(Vector* v) {
    free(v->array);
    free(v);
}

// Frees each element of a vector with given deallocator, and frees itself.
void Vector_freeA(Vector* v, void(*elementFree)(void*)) {
    for (size_t i = 0; i < v->length; i++) {
        elementFree(v->array[i]);
    }
    free(v->array);
    free(v);
}

// Returns the element at the given index.
void* Vector_at(const Vector* v, size_t idx) {
    return v->array[idx];
}

// Resizes a vector to a given size and returns the vector in the new space.
Vector* Vector_resize(Vector* v, size_t newSize) {
    void* newArray = realloc(v->array, newSize * v->width);
    if (newArray == NULL) return NULL;
    v->array = newArray;
    v->size = newSize;
    return v;
}

// Pushes a new element on to the vector, expanding the size if necessary.
void* Vector_push(Vector* v, void* e) {
    if (v->length >= v->size && Vector_resize(v, v->size * 2) == NULL) {
        return NULL; 
    }

    v->array[v->length] = e;
    return v->array[v->length++];
}

// Pops an element off of the vector, shrinking the size if necessary.
void* Vector_pop(Vector* v) {
    if (v->length <= 0 || 
        (v->length < v->size / 4 && Vector_resize(v, v->size / 2) == NULL)) 
    {
        return NULL;
    }

    return v->array[--v->length];
}

// Sets the length of the vector to 0.
void Vector_clear(Vector* v) {
    v->length = 0;
}
