/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:34:55 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 16:24:10 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	deg2rad(int angle)
{
	return (angle * M_PI / 180);
}

t_vector3	rotate_x(t_vector3 p, int angle)
{
	t_vector3	rotated;
	float		rad;

	rad = deg2rad(angle);
	rotated.x = p.x;
	rotated.y = cos(rad) * p.y - sin(rad) * p.z;
	rotated.z = sin(rad) * p.y + cos(rad) * p.z;
	return (rotated);
}

t_vector3	rotate_y(t_vector3 p, int angle)
{
	t_vector3	rotated;
	float		rad;

	rad = deg2rad(angle);
	rotated.x = cos(rad) * p.x + sin(rad) * p.z;
	rotated.y = p.y;
	rotated.z = -sin(rad) * p.x + cos(rad) * p.z;
	return (rotated);
}

t_vector3	rotate_z(t_vector3 p, int angle)
{
	t_vector3	rotated;
	float		rad;

	rad = deg2rad(angle);
	rotated.x = cos(rad) * p.x - sin(rad) * p.y;
	rotated.y = sin(rad) * p.x + cos(rad) * p.y;
	rotated.z = p.z;
	return (rotated);
}
