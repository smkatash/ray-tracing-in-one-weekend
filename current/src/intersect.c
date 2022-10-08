/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:12:53 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/07 21:35:44 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"

bool    objectListIntersect(t_ray *ray, double t_min, double t_max, t_intersect *rec, t_objects **objList)
{
    t_intersect record;
    t_objects   *temp;
    bool hit_something = false;
    double closest = t_max;
    
    temp = *objList;
    while (temp)
    {
        if (objectIntersect(ray, t_min, closest, temp->object->sphere, &record))
        {
            hit_something = true;
            closest = record.t;
            rec = &record;
        }
        temp = temp->next;
    }
    
    return (hit_something);
}
