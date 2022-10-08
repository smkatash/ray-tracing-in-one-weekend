#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "object.h"
#include "memory.h"
#include <stdlib.h>

typedef struct s_vector {
   void** array;
   size_t length;
   size_t width;
   size_t size;
} t_vector;

typedef struct s_objectlist {
	t_object    sphere;
	t_vector    *objects;
} t_objectlist;

t_objectlist *ft_lstnew();
void          ft_lstfree(t_objectlist* hittableList);
void          push_back(t_objectlist* hittableList, t_object* object);
void          ft_lstclear(t_objectlist* hittableList);

t_vector     *vector_new(size_t size, size_t width);
void          vector_free(t_vector* v);
void          vector_free_at(t_vector* v, void(*free_element)(void*));
void         *vector_at(const t_vector* v, size_t index);
t_vector     *vector_realloc(t_vector* v, size_t new_size); 
void         *vector_pushback(t_vector* v, void* element);
void         *vector_pop(t_vector* v);
void          vector_clear(t_vector* v);

#endif