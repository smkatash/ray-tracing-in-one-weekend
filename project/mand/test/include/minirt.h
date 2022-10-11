/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:12 by aiarinov          #+#    #+#             */
/*   Updated: 2022/10/07 19:01:05 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "vec3.h"
# include "./minilibx/mlx.h"

# define KEY_ESC		65307
# define KEY_CAM_R		65363
# define KEY_CAM_L		65361

# define WIN_START	"\nScene is being rendered...\n"
# define WIN_KEY	"Press right / left keys to change cameras. "
# define WIN_EXIT	"Press ESC key or X on the window to exit.\n"
# define WIN_END	"Exiting miniRT...\n"
# define SAVE_IMG	"\nSaving the image(s)...\n"

# define EPSILON	0.0001
# define ALBEDO		1000

typedef struct	s_rt
{
	bool		save;
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_scene		scene;
}				t_rt;

typedef struct	s_hit
{
	float		time;
	t_coord		point;
	t_coord		normal;
	int			colour;
	void		*obj;
}				t_hit;

typedef struct	s_ray
{
	t_coord		p_ori;
	t_coord		v_dir;
	t_hit		hit;
}				t_ray;


// typedef struct s_vector
// {
// 	float	x;
// 	float	y;
// 	float	z;

// }	t_vector;

// typedef struct s_sphere
// {
// 	t_vector	*center;
// 	float		radius;
// }	t_sphere;

// typedef struct s_camera
// {
// 	t_vector	*origin;
// 	t_vector	*direction;
// 	float		fov;
// }	t_camera;

// typedef struct s_scene
// {
// 	t_camera *cams;
// 	t_sphere *sphere;
// 	float width;
// 	float hight;
// }	t_scene;

// typedef struct s_vplane
// {
// 	float	width;
// 	float	hight;
// 	float	x_pixel;
// 	float	y_pixel;

// }	t_vplane;

void	error_exit(int code);

t_vector	*new_vector(float x, float y, float z);
t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2);
float	vec_length(t_vector *vec);
void	vec_normalize(t_vector *vec);
float	vec_dot_product(t_vector *vec1, t_vector *vec2);

t_camera	*new_cam(t_vector *origin, t_vector *direction, float fov);

t_sphere	*new_sphere(t_vector *center, float radius);

t_scene	*new_scene(t_camera *cam, t_sphere *sphere);

t_vplane	*get_view_plane(float width, float hight, float fov);

int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere);

void	ray_tracing(void *mlx, void *window, t_scene *scene);
#endif
