/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:36:13 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/14 20:16:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

t_vector*	vector_new(size_t size, size_t width)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->width = width;
	new->size = size;
	new->length = 0;
	new->array = malloc(size * width);
	return (new);
}

void    vector_free(t_vector* v)
{
	free(v->array);
	free(v);
}

void    *vector_at(const t_vector* v, size_t index)
{
	return (v->array[index]);
}

void    vector_free_at(t_vector* v, void(*free_element)(void*))
{
	for (size_t i = 0; i < v->length; i++)
	{
		free_element(v->array[i]);
	}
	free(v->array);
	free(v);
}

t_vector    *vector_realloc(t_vector* v, size_t new_size)
{   
	void	*new;
	
	new = realloc(v->array, new_size * v->width);
	if (!new)
		return (NULL);
	v->array = new;
	v->size = new_size;
	return (v);
}

void	*vector_pushback(t_vector* v, void* element)
{
	if (v->length >= v->size && vector_realloc(v, v->size * 2) == NULL)
		return (NULL);
	v->array[v->length] = element;
	return (v->array[v->length++]);
}

void	*vector_pop(t_vector* v)
{
	if (v->length <= 0 || (v->length < v->size / 4 && vector_realloc(v, v->size / 2) == NULL))
		return (NULL);
	return (v->array[--v->length]);
}

void	vector_clear(t_vector* v)
{
	v->length = 0;
}
