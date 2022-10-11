/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:01:41 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/07 19:02:26 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include <stdbool.h>
# include "libft.h"
# include "vec3.h"

typedef enum	e_type {
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}				t_type;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct		s_resol
{
	int				x;
	int				y;
}					t_resol;

typedef struct		s_amb_li
{
	double			ratio;
	int				colour;

}					t_amb_li;

typedef struct		s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_cam
{
	t_img			img;
	t_coord			point;
	t_coord			normal;
	float			fov;
	t_coord			hor;
	t_coord			ver;
	t_coord			llc;
	struct s_cam	*next;
	struct s_cam	*prev;
}					t_cam;

typedef struct		s_elem
{
	t_coord			point;
	t_coord			normal;
	t_coord			*vertex;
	short int		qtd_vertex;
	int				colour;
	double			ratio;
	double			diam;
	double			height;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_scene
{
	char			*line;
	char			**split;
	t_resol			resol;
	t_amb_li		amb_li;
	t_cam			*cam;
	t_elem			*light;
	t_elem			*sp;
	t_elem			*pl;
	t_elem			*sq;
	t_elem			*cy;
	t_elem			*tr;
	short int		qtys[9];
}					t_scene;

typedef void		(*t_arr_sc)(t_scene *, t_elem **);

#endif