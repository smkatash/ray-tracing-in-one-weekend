/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:44:03 by kanykei           #+#    #+#             */
/*   Updated: 2022/10/11 16:21:06 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "rt.h"

void	put_color(t_vec3 *pixels, int spp)
{
	double	scale;
	int	x;
	int	y;
	int	z;

	scale = 1.0 / spp;
	double r = pixels->x * scale;
	double g = pixels->y * scale;
	double b = pixels->z * scale;
	x = 256 * clamp(r, 0.0, 0.999);
	y = 256 * clamp(g, 0.0, 0.999);
	z = 256 * clamp(b, 0.0, 0.999);

	printf("%d %d %d\n", x, y, z);
}
