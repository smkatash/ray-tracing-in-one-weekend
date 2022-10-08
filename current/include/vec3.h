#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>
#include <math.h>

typedef struct s_vec3 {
    double x;
    double y;
    double z;
} t_vec3;

// inline t_vec3* Vec3_opErr(t_vec3* res, const t_vec3* a, const t_vec3* b, 
//                       double(*op)(double, double), int(*err)(double, double))
// {
//     if (err(a->x, b->x) || err(a->y, b->y) || err(a->z, b->z)) return NULL;
//     res->x = op(a->x, b->x);
//     res->y = op(a->y, b->y);
//     res->z = op(a->z, b->z);
//     return res;
// }

// inline t_vec3* Vec3_opErrS(t_vec3* res, const t_vec3* vec, double s,
//                        double(*op)(double, double), int(*err)(double, double))
// {
//     if (err(vec->x, s) || err(vec->y, s) || err(vec->z, s)) return NULL;
//     res->x = op(vec->x, s);
//     res->y = op(vec->y, s);
//     res->z = op(vec->z, s);
//     return res;
// }

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

t_vec3* addition(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_add_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_minus_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_multiply_t(t_vec3* new, const t_vec3* v, double s);
t_vec3* divide(t_vec3* new, const t_vec3* u, const t_vec3* v);
t_vec3* vector_divide_t(t_vec3* new, const t_vec3* v, double s);
double  sum_one_vector(const t_vec3 *vec);
double  dot_product(t_vec3 *u, t_vec3 *v);
t_vec3  *cross_product(t_vec3 *new, t_vec3 *u, t_vec3 *v);
t_vec3  *vector_set_each(t_vec3 *new, double x, double y, double z);
double length_sqrt(const t_vec3* vec);
t_vec3* norm_vec3(t_vec3* res, const t_vec3* vec);

#endif
