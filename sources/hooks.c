/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:34:07 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 17:56:46 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_mouse_pos(int x, int y, t_env *e)
{
	e->mouse_pos.x = x;
	e->mouse_pos.y = y;
	return (0);
}

void	update_zoom(t_env *e)
{
	int	y;

	y = e->mouse_pos.y - e->mouse_pos_init.y;
	e->zoom = d_max(0.1, d_min(10, e->zoom_init - y / 200.0));
}

void	update_rotation(t_env *e)
{
	e->rotation.x = e->mouse_pos.x - e->mouse_pos_init.x + e->rotation_init.x;
	e->rotation.y = e->mouse_pos.y - e->mouse_pos_init.y + e->rotation_init.y;
}

void	update_pan(t_env *e)
{
	e->pan.x = e->mouse_pos.x - e->mouse_pos_init.x + e->pan_init.x;
	e->pan.y = e->mouse_pos.y - e->mouse_pos_init.y + e->pan_init.y;
}
