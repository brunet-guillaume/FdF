/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:11:03 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 18:11:18 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_view(t_env *e)
{
	e->rotation.x = 0;
	e->rotation.y = 0;
	e->pan.x = 0;
	e->pan.y = 0;
	e->zoom = 3;
	e->map.z_scale = 1;
}

int	press_key(int keycode, t_env *e)
{
	if (keycode == ESC_KEY)
		close_win(e);
	else if (keycode == LEFT_CTRL_KEY || keycode == RIGHT_CTRL_KEY)
	{
		e->mouse_pos_init = e->mouse_pos;
		e->rotation_init = e->rotation;
		e->ctrl_down = 1;
	}
	else if (keycode == LEFT_SHIFT_KEY || keycode == RIGHT_SHIFT_KEY)
	{
		e->mouse_pos_init = e->mouse_pos;
		e->pan_init = e->pan;
		e->shift_down = 1;
	}
	else if (keycode == CAPS_LOCK_KEY)
	{
		e->mouse_pos_init = e->mouse_pos;
		e->zoom_init = e->zoom;
		e->caps_lock_down = 1;
	}
	else if (keycode == BACKSPACE_KEY)
		reset_view(e);
	if (keycode == RETURN_KEY)
		e->parallel = toggle(e->parallel);
	return (0);
}

int	up_key(int keycode, t_env *e)
{
	if (keycode == LEFT_CTRL_KEY || keycode == RIGHT_CTRL_KEY)
		e->ctrl_down = 0;
	if (keycode == LEFT_SHIFT_KEY || keycode == RIGHT_SHIFT_KEY)
		e->shift_down = 0;
	if (keycode == CAPS_LOCK_KEY)
		e->caps_lock_down = 0;
	return (0);
}

void	change_z_scale(int coef, t_env *e)
{
	e->map.z_scale -= coef * 0.25;
}

int	mouse_hook(int btn, int x, int y, t_env *e)
{
	if (btn == 3)
		e->custom_clr = toggle(e->custom_clr);
	else if (btn == 1)
		check_click(x, y, e);
	else if (btn == 5)
		change_z_scale(1, e);
	else if (btn == 4)
		change_z_scale(-1, e);
	return (0);
}
