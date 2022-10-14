/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:59:34 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/14 22:18:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdlib.h>
#include <stdio.h>
#define NEAR_ZERO 1e-8
#define PI 3.14159265358979323846

inline double random_double(void)
{
	// Returns a random real in [0,1).
	return (rand() / (RAND_MAX + 1.0));
}

inline double random_double_minmax(double min, double max) 
{
	// Returns a random real in [min,max).
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


// A rejection method. First, pick a random point in the unit cube 
// where x, y, and z all range from −1 to +1. Reject this point and 
// try again if the point is outside the sphere.
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
    return (unit_vector(vec, random_in_unit_sphere(vec)));
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
    // Return true if the vector is close to zero in all dimensions.
	return (fabs(vec->x) < NEAR_ZERO) && (fabs(vec->y) < NEAR_ZERO) && (fabs(vec->z) < NEAR_ZERO);
}

inline void* reflect(t_vec3* vec, const t_vec3* v, const t_vec3* normal) 
{
	vector_multiply_t(vec, normal, 2 * dot_product(v, normal));
	substraction(vec, v, vec);
	return (vec);
}

inline void* refract(t_vec3 *vec, const t_vec3 *uv, const t_vec3 *n, double etai_over_etat) 
{
    double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_parallel;
	t_vec3	neg;
	
	vector_multiply_t(&neg, uv, -1);
	cos_theta = fmin(dot_product(&neg, n), 1.0);
	vector_multiply_t(&r_out_perp, addition(&r_out_perp, uv, vector_multiply_t(&r_out_perp, n, cos_theta)), etai_over_etat);
	vector_multiply_t(&r_out_parallel, n, -1 * sqrt(fabs(1.0 - length_v3(&r_out_perp))));
    addition(vec, &r_out_perp, &r_out_parallel);
	return (vec);
}

inline double degrees_to_radians(double deg) 
{
    return (deg * PI / 180.0);
}

inline void* random_in_unit_disk(t_vec3 *vec) 
{
    while (1) 
	{
		vector_set_each(vec, random_double_minmax(-1, 1), random_double_minmax(-1, 1), 0);
        if (length_v3(vec) < 1) 
			break ;	
    }
	return (vec);
}


#endif
