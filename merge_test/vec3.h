#ifndef VEC3_H
#define VEC3_H

#include "rt.h"
#include <stdio.h>
#include <math.h>


inline t_vec3* vector_operation(t_vec3* new, const t_vec3* u, const t_vec3* v, 
                   double(*operation)(double, double)) 
{
    new->x = operation(u->x, v->x);
    new->y = operation(u->y, v->y);
    new->z = operation(u->z, v->z);
    return (new);
}

inline t_vec3* vector_Toperation(t_vec3* new, const t_vec3* v, double t, 
                    double(*operation)(double, double))
{
    new->x = operation(v->x, t);
    new->y = operation(v->y, t);
    new->z = operation(v->z, t);
    return (new);
}

inline t_vec3* vector_exception(t_vec3* new, const t_vec3* u, const t_vec3* v, 
                      double(*operation)(double, double), int(*error)(double, double))
{
    if (error(u->x, v->x) || error(u->y, v->y) || error(u->z, v->z)) 
        return NULL;
    new->x = operation(u->x, v->x);
    new->y = operation(u->y, v->y);
    new->z = operation(u->z, v->z);
    return new;
}

inline t_vec3* vector_Texception(t_vec3* new, const t_vec3* v, double t,
                       double(*operation)(double, double), int(*error)(double, double))
{
    if (error(v->x, t) || error(v->y, t) || error(v->z, t)) 
        return NULL;
    new->x = operation(v->x, t);
    new->y = operation(v->y, t);
    new->z = operation(v->z, t);
    return new;
}


t_vec3* addition(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_add_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_minus_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_multiply_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* divide(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_divide_t(t_vec3* new, const t_vec3* v, double s);
double  sum_one_vector(const t_vec3 *vec);
double  dot_product(const t_vec3 *u, const t_vec3 *v);
t_vec3  *cross_product(t_vec3 *new, const t_vec3 *u, const t_vec3 *v);
t_vec3  *vector_set_each(t_vec3 *new, double x, double y, double z);
double length_sqrt(const t_vec3* vec);
t_vec3* norm_vec3(t_vec3* res, const t_vec3* vec);


#endif
