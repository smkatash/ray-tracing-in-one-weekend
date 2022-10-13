/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:59:34 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/13 10:43:45 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdlib.h>
#include <stdio.h>
#define NEAR_ZERO 1e-8
#define PI 3.14159265358979323846

// double random_double(void) __attribute__((always_inline));
// double random_double_minmax(double min, double max) __attribute__((always_inline));
// double clamp(double x, double min, double max) __attribute__((always_inline));

inline double random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

inline double random_double_minmax(double min, double max) 
{
	return (min + (max-min) * random_double());
}

inline double clamp(double x, double min, double max) 
{
	if (x < min)
		return (min);
	if (x > max)
		return max;
	return (x);
}

inline void* random_vector(t_vec3* vec) 
{
    vector_set_each(vec, random_double(), random_double(), random_double());
	return (vec);
}

inline void* random_minmax_vector(t_vec3* vec, double min, double max) 
{
    vector_set_each(vec, random_double_minmax(min, max), random_double_minmax(min, max), random_double_minmax(min, max));
	return (vec);
}


static inline void* random_in_unit_sphere(t_vec3 *vec) 
{
    while (1) 
	{
        random_minmax_vector(vec, -1, 1);
		if (length_v3(vec) < 1)
			break ;
    }
	return (vec);
}

inline void* random_unit_vector(t_vec3 *vec) 
{
    return unit_vector(vec, random_in_unit_sphere(vec));
}

inline void* random_in_hemisphere(t_vec3 *random, t_vec3 *normal) 
{
	random_in_unit_sphere(random);
    if (dot_product(random, normal) > 0.0)
        return (random);
    else
        return (vector_multiply_t(random, random, -1));
}

inline int near_zero(t_vec3* vec) 
{
    return (fabs(vec->x) < NEAR_ZERO) && (fabs(vec->y) < NEAR_ZERO) && (fabs(vec->z) < NEAR_ZERO);
}

inline void* reflect(t_vec3* vec, const t_vec3* v, const t_vec3* normal) 
{
	vector_multiply_t(vec, normal, 2 * dot_product(v, normal));
	substraction(vec, v, vec);
	return (vec);
}


#endif
