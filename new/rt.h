/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:59:34 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/11 16:31:50 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

#include <stdlib.h>
#include <stdio.h>

// double random_double(void) __attribute__((always_inline));
// double random_double_minmax(double min, double max) __attribute__((always_inline));
// double clamp(double x, double min, double max) __attribute__((always_inline));

double random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double random_double_minmax(double min, double max) 
{
	return (min + (max-min) * random_double());
}

double clamp(double x, double min, double max) 
{
	if (x < min)
		return (min);
	if (x > max)
		return max;
	return (x);
}

#endif