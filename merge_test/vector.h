#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
   void** array;
   size_t length;
   size_t width;
   size_t size;
} Vector;

// Returns a malloced vector with the given size.
Vector* Vector_new(size_t size, size_t width);

// Frees the vector.
void Vector_free(Vector* v);

// Frees each element of a vector with given deallocator, and frees itself.
void Vector_freeA(Vector* v, void(*elementFree)(void*));

// Returns the element at the given index.
void* Vector_at(const Vector* v, size_t idx);

// Resizes a vector to a given size and returns the vector in the new space.
Vector* Vector_resize(Vector* v, size_t newSize); 

// Pushes a new element on to the vector, expanding the size if necessary.
void* Vector_push(Vector* v, void* e);

// Pops an element off of the vector, shrinking the size if necessary.
void* Vector_pop(Vector* v);

// Sets the length of the vector to 0.
void Vector_clear(Vector* v);

#endif
