/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:57:26 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 11:45:26 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector3	scale_height(t_vector3 p, float s)
{
	t_vector3	scaled;
	scaled.x = p.x;
	scaled.y = p.y;
	scaled.z = p.z * s;
	return (scaled);
}

t_vector3	scale(t_vector3 p, float s)
{
	t_vector3	scaled;
	scaled.x = p.x * s;
	scaled.y = p.y * s;
	scaled.z = p.z * s;
	return (scaled);
}

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

	tp = center(p, e);
	tp = scale_height(tp, e->map.z_scale);
	tp = scale(tp, e->zoom);
	tp = rotateZ(tp, 45 + -e->rotation.x / 4);
	tp = rotateX(tp, 45 + -e->rotation.y / 4);
	tp = center_in_view(tp);
	tp = pan(tp, e);
	return (tp);
}

t_vector3	parallel_tr(t_vector3 p, t_env *e)
{
	t_vector3	tp;

	tp = center(p, e);
	tp = scale_height(tp, e->map.z_scale);
	tp = scale(tp, e->zoom);
	tp = rotateZ(tp, 90);
	tp = rotateX(tp, 90);
	tp.y += p.x * 1.2 * e->zoom / 2 - e->zoom * 2.2 * e->map.x_max;
	tp.x -= p.x * 1.2 * e->zoom / 2 - e->zoom * 2.2 * e->map.y_max;
	tp = center_in_view(tp);
	tp = pan(tp, e);
	return (tp);
}
