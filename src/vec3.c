/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:02:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 22:06:38 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"

// Sum of two vectors
void* addition(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    new->x = u->x + v->x;
    new->y = u->y + v->y;
    new->z = u->z + v->z;
    return (new);
}

// Adding a scalar to vectors' components 
void* vector_add_t(t_vec3* new, const t_vec3* v, double t) 
{
    new->x = v->x + t;
    new->y = v->y + t;
    new->z = v->z + t;
    return (new);
}

// Difference of two vectors
void* substraction(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    new->x = u->x - v->x;
    new->y = u->y - v->y;
    new->z = u->z - v->z;
    return (new);
}

// Multiply vectors' components
void* multiply(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    new->x = u->x * v->x;
    new->y = u->y * v->y;
    new->z = u->z * v->z;
    return (new);
}

// Scalar multiplication is multiplying a vector by a constant.
void* vector_multiply_t(t_vec3* new, const t_vec3* v, double t) 
{
    new->x = t * v->x;
    new->y = t * v->y;
    new->z = t * v->z;
    return (new);
}

// Dividing vector's components by a scalar.
void* vector_divide_t(t_vec3* new, const t_vec3* v, double t) 
{
   return (vector_multiply_t(new, v, 1/t));
}

// Sum components of a vector 
double sum_one_vector(const t_vec3* v) 
{
    return (v->x + v->y + v->z);
}

// Dot product of the magnitudes of the two vectors 
// and the cosine of the angle between the two vectors. 
double dot_product(const t_vec3* u, const t_vec3* v) 
{
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

// Scalar of a vector
double length_v3(const t_vec3* v) 
{
    return (dot_product(v, v));
}

// Squareroot of a scalar of a vector
double length_sqrt(const t_vec3* v) 
{
    return (sqrt(length_v3(v)));
}

//The unit vector in the same direction of any nonzero vector 
// is found by dividing the vector by its magnitude.
void* unit_vector(t_vec3 *new, const t_vec3* v) 
{
   double len = length_sqrt(v);
   return (vector_divide_t(new, v, len));
}

// Vector which is perpendicular to the surface at a given point.
void* norm_vec3(t_vec3* new, const t_vec3* v) 
{
    return (vector_divide_t(new, v, length_sqrt(v)));
}

// The cross product formula gives the magnitude of the resultant 
// vector which is the area of the parallelogram that is spanned 
// by the two vectors.
void *cross_product(t_vec3* new, const t_vec3* u, const t_vec3* v) 
{
    new->x = (u->y*v->z) - (u->z*v->y);
    new->y = (u->z*v->x) - (u->x*v->z);
    new->z = (u->x*v->y) - (u->y*v->x);
    return (new);
}

// Sets each coordinate of a vector to defined values
void  *vector_set_each(t_vec3 *new, double x, double y, double z)
{
    new->x = x;
    new->y = y;
    new->z = z;
    return (new);
}
