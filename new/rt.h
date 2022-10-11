/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:59:34 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/11 21:06:50 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdlib.h>
#include <stdio.h>

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


inline void* random_in_unit_sphere(t_vec3 *vec) 
{
    while (1) 
	{
        random_minmax_vector(vec, -1, 1);
		if (length_v3(vec) < 1)
			break ;
    }
	return (vec);
}

#endif