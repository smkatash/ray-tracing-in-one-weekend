/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:14:02 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/14 22:33:35 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/camera.h"

t_camera *set_camera(t_camera *cam, double ratio, double vfov)
{
    t_vec3  temp;
    t_vec3 look_from = (t_vec3){13,2,3};
    t_vec3 look_at = (t_vec3){0,0,0};
    t_vec3 vup = (t_vec3){0,1,0};
    double focus_dist = 10.0;
    double aperture = 0.01;

    double viewport_height = 2.0 * tan(degrees_to_radians(vfov) / 2);
    double viewport_width = ratio * viewport_height;
    unit_vector(&cam->w, substraction(&cam->w, &look_from, &look_at));
    unit_vector(&cam->u, cross_product(&cam->u, &vup, &cam->w));
    cross_product(&cam->v, &cam->w, &cam->u);
    cam->origin = look_from;
    vector_multiply_t(&cam->horizontal, &cam->u, viewport_width * focus_dist);
    vector_multiply_t(&cam->vertical, &cam->v, viewport_height  * focus_dist);
    
    vector_divide_t(&temp, &cam->horizontal, 2);
    substraction(&cam->lower_left_corner, &cam->origin, &temp);
    vector_divide_t(&temp, &cam->vertical, 2);
    substraction(&cam->lower_left_corner, &cam->lower_left_corner, &temp);
    vector_multiply_t(&temp, &cam->w, focus_dist);
    substraction(&cam->lower_left_corner, &cam->lower_left_corner, &temp);
    cam->lens_radius = aperture / 2;
    return (cam);
}
