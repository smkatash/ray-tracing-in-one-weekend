/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 00:46:35 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdio.h>

// extern t_vec3* vector_operation(t_vec3* new, const t_vec3* u, const t_vec3* v, 
//                    double(*operation)(double, double));

// extern t_vec3* vector_Toperation(t_vec3* new, const t_vec3* v, double t, 
//                     double(*operation)(double, double));

// extern t_vec3* vector_exception(t_vec3* new, const t_vec3* u, const t_vec3* v, 
//                       double(*operation)(double, double), int(*error)(double, double));

// extern t_vec3* vector_Texception(t_vec3* new, const t_vec3* v, double t,
//                        double(*operation)(double, double), int(*error)(double, double));               

// static inline double add(double u, double v) 
// {
//     return (u + v);
// }

// static inline double minus(double u, double v) 
// {
//     return (u - v);
// }

// static inline double star(double u, double v) 
// {
//     return (u * v);
// }

// static inline int division_error(double u, double v) 
// {
//     return (v == 0);
// }

// static inline double division(double u, double v) 
// {
//     return (u / v);
// }


// t_vec3* addition(t_vec3* new, const t_vec3* u, const t_vec3* v) 
// {
//     return (vector_operation(new, u, v, add));
// }

// t_vec3* vector_add_t(t_vec3* new, const t_vec3* v, double t) 
// {
//     return (vector_Toperation(new, v, t, add));
// }

// t_vec3* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v) 
// {
//     return (vector_operation(new, u, v, minus));
// }

// t_vec3* vector_minus_t(t_vec3* new, const t_vec3* v, double t) 
// {
//     return (vector_Toperation(new, v, t, minus));
// }

// t_vec3* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v) 
// {
//     return (vector_operation(new, u, v, star));
// }

// t_vec3* vector_multiply_t(t_vec3* new, const t_vec3* v, double t) 
// {
//     return (vector_Toperation(new, v, t, star));
// }

// t_vec3* divide(t_vec3* new, const t_vec3* u, const t_vec3* v) 
// {
//     return (vector_exception(new, u, v, division, division_error));
// }

// t_vec3* vector_divide_t(t_vec3* new, const t_vec3* v, double t) 
// {
//     return (vector_Texception(new, v, t, division, division_error));
// }

// double sum_one_vector(const t_vec3 *vec)
// {
//     return (vec->x + vec->y + vec->z);
// }

// inline double  dot_product(const t_vec3 *u, const t_vec3 *v)
// {
//     return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
// }

// t_vec3  *cross_product(t_vec3 *new, t_vec3 *u, t_vec3 *v)
// {
//     new->x = (u->y * v->z) - (u->z * v->y);
//     new->y = (u->z * v->x) - (u->x * v->z);
//     new->z = (u->z * v->y) - (u->y * v->x);
//     return (new);
// }

// t_vec3  *vector_set_each(t_vec3 *new, double x, double y, double z)
// {
//     new->x = x;
//     new->y = y;
//     new->z = z;
//     return (new);
// }

// inline double length_v3(const t_vec3* vec) 
// {
//     return dot_product(vec, vec);
// }

// double length_sqrt(const t_vec3* vec) 
// {
//     return (sqrt(length_v3(vec)));
// }

// t_vec3* norm_vec3(t_vec3* new, const t_vec3* vec)
// {
//     return (vector_divide_t(new, vec, length_sqrt(vec)));
// }

// Sets each element of new to op(corresponding elements of u and v).
// Returns 0 if err(corresponding elements of u and v) returns 1. Otherwise, 1.
extern t_vec3* vector_exception(t_vec3* new, const t_vec3* u, const t_vec3* v, 
                      double(*op)(double, double), int(*err)(double, double));

// Sets each element of new to op(corresponding element of vec, s).
// Returns 0 if err(corresponding element of vec, s) returns 1. Otherwise, 1.
extern t_vec3* vector_Texception(t_vec3* new, const t_vec3* vec, double s, 
                       double(*op)(double, double), int(*err)(double, double));

// Sets each element of new to op(corresponding elements of u and v).
extern t_vec3* vector_operation(t_vec3* new, const t_vec3* u, const t_vec3* v, 
                   double(*op)(double, double));

// Sets each element of new to op(corresponding element of vec, s).
extern t_vec3* vector_Toperation(t_vec3* new, const t_vec3* vec, double s, 
                    double(*op)(double, double));

static inline double add(double u, double v) {
    return u + v;
}

// Sets new to u + v.
t_vec3* addition(t_vec3* new, const t_vec3* u, const t_vec3* v) {
    return vector_operation(new, u, v, add);
}

// Sets new to vec + s.
t_vec3* vector_add_t(t_vec3* new, const t_vec3* vec, double s) {
    return vector_Toperation(new, vec, s, add);
}

static inline double minus(double u, double v) {
    return u - v;
}

// Sets new to u - v.
t_vec3* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v) {
    return vector_operation(new, u, v, minus);
}

// Sets new to vec - s.
t_vec3* vector_minus_t(t_vec3* new, const t_vec3* vec, double s) {
    return vector_Toperation(new, vec, s, minus);
}

static inline double star(double u, double v) {
    return u * v;
}

// Sets new to u * v.
t_vec3* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v) {
    return vector_operation(new, u, v, star);
}

// Sets new to vec * s.
t_vec3* vector_multiply_t(t_vec3* new, const t_vec3* vec, double s) {
    return vector_Toperation(new, vec, s, star);
}

static inline double division(double u, double v) {
    return u / v;
}

// Returns 1 if v is 0, otherwise 0.
static inline int exception(double u, double v) {
    return v == 0;
}

// Sets new to u / v.
t_vec3* divide(t_vec3* new, const t_vec3* u, const t_vec3* v) {
    return vector_exception(new, u, v, division, exception);
}

// Sets new to vec / s.
t_vec3* vector_divide_t(t_vec3* new, const t_vec3* vec, double s) {
    return vector_Texception(new, vec, s, division, exception);
}

// Returns the sum of all elements in the vector.
double sum_one_vector(const t_vec3* vec) {
    return vec->x + vec->y + vec->z;
}

// Returns the dot product of A and B.
inline double dot_product(const t_vec3* u, const t_vec3* v) {
    return (u->x * v->x) + (u->y * v->y) + (u->z * v->z);
}

// Returns the magnitude squared of u vector.
inline double length_v3(const t_vec3* vec) {
    return dot_product(vec, vec);
}

// Returns the magnitude of u vector.
double length_sqrt(const t_vec3* vec) {
    return sqrt(length_v3(vec));
}

// Sets new to the vector normalized.
t_vec3* norm_vec3(t_vec3* new, const t_vec3* vec) {
    return vector_divide_t(new, vec, length_sqrt(vec));
}

// Sets new to the cross product.
t_vec3 *cross_product(t_vec3* new, const t_vec3* u, const t_vec3* v) {
    new->x = (u->y*v->z) - (u->z*v->y);
    new->y = (u->z*v->x) - (u->x*v->z);
    new->z = (u->z*v->y) - (u->y*v->x);
    return new;
}

t_vec3  *vector_set_each(t_vec3 *new, double x, double y, double z)
{
    new->x = x;
    new->y = y;
    new->z = z;
    return (new);
}
