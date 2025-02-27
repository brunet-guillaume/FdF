/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:57:26 by gbrunet           #+#    #+#             */
/*   Updated: 2024/01/03 11:44:27 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector3	center(t_vector3 p, t_env *e)
{
	t_vector3	centered;

	centered.x = p.x - (e->map.x_max * 10) / 2;
	centered.y = p.y - (e->map.y_max * 10) / 2;
	centered.z = p.z;
	return (centered);
}

t_vector3	center_in_view(t_vector3 p)
{
	t_vector3	centered;

	centered.x = p.x + WIN_WIDTH / 2;
	centered.y = p.y + WIN_HEIGHT / 2;
	centered.z = p.z;
	return (centered);
}

t_vector3	pan(t_vector3 p, t_env *e)
{
	t_vector3	panned;

	panned.x = p.x + e->pan.x;
	panned.y = p.y + e->pan.y;
	panned.z = p.z;
	return (panned);
}

t_vector3	transform(t_vector3 p, t_env *e)
{
	t_vector3	tp;
	float		scl;

	tp = center(p, e);
	scl = 100.0 / max(e->map.x_max, e->map.y_max);
	tp = scale(tp, scl);
	tp = rotate_z(tp, 45);
	tp = rotate_x(tp, 45);
	tp = center_in_view(tp);
	return (tp);
}
