/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:25:27 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/08 18:02:32 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"

typedef struct s_camera {
    t_vec3 origin;
    t_vec3 horizontal;
    t_vec3 vertical;
    t_vec3 lower_left_corner;
    t_vec3 focal;
}   t_camera;

t_camera *set_camera(t_camera *cam, double ratio);

#endif