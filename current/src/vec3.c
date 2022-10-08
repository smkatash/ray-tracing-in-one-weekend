/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/09 01:03:08 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"

extern t_vec3* vector_operation(t_vec3* new, const t_vec3* u, const t_vec3* v, 
                   double(*operation)(double, double));

extern t_vec3* vector_Toperation(t_vec3* new, const t_vec3* v, double t, 
                    double(*operation)(double, double));

static inline double add(double u, double v) 
{
    return (u + v);
}

static inline double minus(double u, double v) 
{
    return (u + v);
}

static inline double star(double u, double v) 
{
    return (u * v);
}

static inline double division(double u, double v) 
{
    if (v == 0)
    {
        fprintf(2, "Floating point error");
        return (0);
    }
    return (u / v);
}

t_vec3* addition(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    return (vector_operation(new, u, v, add));
}

t_vec3* vector_add_t(t_vec3* new, const t_vec3* v, double s) 
{
    return (vector_Toperation(new, v, s, add));
}

t_vec3* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    return (vector_operation(new, u, v, minus));
}

t_vec3* vector_minus_t(t_vec3* new, const t_vec3* v, double s) 
{
    return (vector_Toperation(new, v, s, minus));
}

t_vec3* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    return (vector_operation(new, u, v, star));
}

t_vec3* vector_multiply_t(t_vec3* new, const t_vec3* v, double s) 
{
    return (vector_Toperation(new, v, s, star));
}

t_vec3* divide(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    return (vector_operation(new, u, v, division));
}

t_vec3* vector_divide_t(t_vec3* new, const t_vec3* v, double s) 
{
    return (vector_Toperation(new, v, s, division));
}

double sum_one_vector(const t_vec3 *vec)
{
    return (vec->x + vec->y + vec->z);
}

double  dot_product(t_vec3 *u, t_vec3 *v)
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

t_vec3  *cross_product(t_vec3 *new, t_vec3 *u, t_vec3 *v)
{
    new->x = (u->y * v->z) - (u->z * v->y);
    new->y = (u->z * v->x) - (u->x * v->z);
    new->z = (u->x * v->y) - (u->y * v->x);
    return (new);
}

t_vec3  *vector_set_each(t_vec3 *new, double x, double y, double z)
{
    new->x = x;
    new->y = y;
    new->z = z;
    return (new);
}

inline double length_v3(const t_vec3* vec) 
{
    return dot_product(vec, vec);
}

double length_sqrt(const t_vec3* vec) 
{
    return sqrt(length_v3(vec));
}


t_vec3* norm_vec3(t_vec3* res, const t_vec3* vec)
{
    return vector_divide_t(res, vec, length_v3(vec));
}

// t_vec3 unit_vector(t_vec3 *v) 
// {
//     t_vec3  uv;
//     double  len;
    
//     len = length(v->x, v->y, v->z);
//     uv = multipl_distance(1/len, v);
//     return (uv);
// }

// void	setNegative(t_vec3 *v)
// {
// 	v->x *= -1;
// 	v->y *= -1;
// 	v->z *= -1;
// }