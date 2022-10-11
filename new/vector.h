/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:37:12 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/11 13:10:16 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_vector {
	void**	array;
	size_t	length;
	size_t	width;
	size_t	size;
}			t_vector;

t_vector	*vector_new(size_t size, size_t width);
void		vector_free(t_vector* v);
void		vector_freeA(t_vector* v, void(*elementFree)(void*));
void		*vector_at(const t_vector* v, size_t idx);
t_vector	*vector_realloc(t_vector* v, size_t newSize); 
void		*vector_pushback(t_vector* v, void* e);
void		*vector_pop(t_vector* v);
void		vector_clear(t_vector* v);

#endif
