/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:12:53 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/07 00:39:31 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"

bool    objectListIntersect(t_ray *ray, double t_min, double t_max, t_intersect *rec, t_objects **objList)
{
    t_objects   *temp;
    t_intersect record;
    bool hit_something = false;
    double closest = t_max;
    
    temp = *objList;
    while (temp)
    {
        if (objectIntersect(ray, t_min, closest, &record))
        {
            hit_something = true;
            closest = record.t;
            rec = &record;
        }
        temp = temp->next;
    }
    return (hit_something);
}
