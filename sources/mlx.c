/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:18:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 18:10:54 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_win(t_env *e)
{
	int	y;

	y = 0;
	while (y < e->map.y_max)
	{
		free(e->map.pts[y]);
		free(e->map.clr[y]);
		y++;
	}
	free(e->map.pts);
	free(e->map.clr);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
	exit(0);
}

int	update(t_env *e)
{
	if (e->ctrl_down)
		update_rotation(e);
	else if (e->shift_down)
		update_pan(e);
	else if (e->caps_lock_down)
		update_zoom(e);
	draw_map(e);
	draw_clrs(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	mlx_string_put(e->mlx, e->win, 40, 25, 0x0000000, "CTRL = Rotation");
	mlx_string_put(e->mlx, e->win, 40, 40, 0x0000000, "SHIFT = Pan");
	mlx_string_put(e->mlx, e->win, 40, 55, 0x0000000, "CAPS LOCK = Zoom");
	mlx_string_put(e->mlx, e->win, 40, 70, 0x0000000,
		"ENTER = Orthographic/Parallel view");
	mlx_string_put(e->mlx, e->win, 40, 85, 0x0000000, "BACKSPACE = Reset view");
	mlx_string_put(e->mlx, e->win, 40, 100, 0x0000000,
		"MOUSE WHEEL = Elevation");
	mlx_string_put(e->mlx, e->win, 40, 115, 0x0000000,
		"RIGHT CLICK = Switch to custom colors");
	mlx_string_put(e->mlx, e->win, 40, 130, 0x0000000, "ESC = Quit");
	return (0);
}

int	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	e->img.img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.l_len,
			&e->img.endian);
	e->ctrl_down = 0;
	e->rotation.x = 0;
	e->rotation.y = 0;
	e->shift_down = 0;
	e->pan.x = 0;
	e->pan.y = 0;
	e->caps_lock_down = 0;
	e->zoom = 3;
	mlx_hook(e->win, 17, (1L << 3), close_win, e);
	mlx_hook(e->win, 6, (1L << 6), get_mouse_pos, e);
	mlx_hook(e->win, 2, (1L << 0), press_key, e);
	mlx_hook(e->win, 3, (1L << 1), up_key, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, update, e);
	mlx_loop(e->mlx);
	return (1);
}
