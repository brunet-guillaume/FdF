/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:18:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 15:05:29 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	d_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	d_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

void	update_zoom(t_env *e)
{
	int y;

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

int	close_win(t_env *e)
{
	int y;
	
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

void	reset_view(t_env *e)
{
	e->rotation.x = 0;
	e->rotation.y = 0;
	e->pan.x = 0;
	e->pan.y = 0;
	e->zoom = 3;
	e->map.z_scale = 1;
}

int toggle(int i)
{
	if (i == 1)
		return (0);
	return (1);
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

void	check_click(int x, int y, t_env *e)
{
	if (x >= 10 && x <= 30)
	{
		if (y >= 10 && y <= 30)
			e->clr_top = rgb(255, 0, 0);
		if (y >= 40 && y <= 60)
			e->clr_top = rgb(0, 255, 0);
		if (y >= 70 && y <= 90)
			e->clr_top = rgb(0, 0, 255);
		if (y >= 100 && y <= 120)
			e->clr_top = rgb(255, 255, 0);
		if (y >= 130 && y <= 150)
			e->clr_top = rgb(255, 0, 255);
		if (y >= 160 && y <= 180)
			e->clr_top = rgb(0, 255, 255);
		if (y >= 190 && y <= 210)
			e->clr_top = rgb(255, 128, 0);
		if (y >= 220 && y <= 240)
			e->clr_top = rgb(255, 0, 128);
		if (y >= 250 && y <= 270)
			e->clr_top = rgb(0, 255, 128);
		if (y >= 280 && y <= 300)
			e->clr_top = rgb(128, 255, 0);
		if (y >= 310 && y <= 330)
			e->clr_top = rgb(128, 0, 255);
		if (y >= 340 && y <= 360)
			e->clr_top = rgb(0, 128, 255);
	
	
		if (y >= WIN_HEIGHT - 360 && y <= WIN_HEIGHT - 340)
			e->clr_bottom = rgb(255, 0, 0);
		if (y >= WIN_HEIGHT - 330 && y <= WIN_HEIGHT - 310)
			e->clr_bottom = rgb(0, 255, 0);
		if (y >= WIN_HEIGHT - 300 && y <= WIN_HEIGHT - 280)
			e->clr_bottom = rgb(0, 0, 255);
		if (y >= WIN_HEIGHT - 270 && y <= WIN_HEIGHT - 250)
			e->clr_bottom = rgb(255, 255, 0);
		if (y >= WIN_HEIGHT - 240 && y <= WIN_HEIGHT - 220)
			e->clr_bottom = rgb(255, 0, 255);
		if (y >= WIN_HEIGHT - 210 && y <= WIN_HEIGHT - 190)
			e->clr_bottom = rgb(0, 255, 255);
		if (y >= WIN_HEIGHT - 180 && y <= WIN_HEIGHT - 160)
			e->clr_bottom = rgb(255, 128, 0);
		if (y >= WIN_HEIGHT - 150 && y <= WIN_HEIGHT - 130)
			e->clr_bottom = rgb(255, 0, 128);
		if (y >= WIN_HEIGHT - 120 && y <= WIN_HEIGHT - 100)
			e->clr_bottom = rgb(0, 255, 128);
		if (y >= WIN_HEIGHT - 90 && y <= WIN_HEIGHT - 70)
			e->clr_bottom = rgb(128, 255, 0);
		if (y >= WIN_HEIGHT - 60 && y <= WIN_HEIGHT - 40)
			e->clr_bottom = rgb(128, 0, 255);
		if (y >= WIN_HEIGHT - 30 && y <= WIN_HEIGHT - 10)
			e->clr_bottom = rgb(0, 128, 255);
	}
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

void	draw_clr(t_vector2 pt, t_rgb_color clr, t_env *e)
{
	t_vector3	p;
	
	p.y = pt.y;
	while (p.y < pt.y + 20)
	{
		p.x = pt.x;
		while (p.x < pt.x + 20)
		{
			put_pxl(&e->img, p, clr);
			p.x++;
		}
		p.y++;
	}
}

t_vector2	vector2(int x, int y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}

void	draw_clrs(t_env *e)
{
	draw_clr(vector2(10, 10), rgb(255, 0, 0), e);
	draw_clr(vector2(10, 40), rgb(0, 255, 0), e);
	draw_clr(vector2(10, 70), rgb(0, 0, 255), e);
	draw_clr(vector2(10, 100), rgb(255, 255, 0), e);
	draw_clr(vector2(10, 130), rgb(255, 0, 255), e);
	draw_clr(vector2(10, 160), rgb(0, 255, 255), e);
	draw_clr(vector2(10, 190), rgb(255, 128, 0), e);
	draw_clr(vector2(10, 220), rgb(255, 0, 128), e);
	draw_clr(vector2(10, 250), rgb(0, 255, 128), e);
	draw_clr(vector2(10, 280), rgb(128, 255, 0), e);
	draw_clr(vector2(10, 310), rgb(128, 0, 255), e);
	draw_clr(vector2(10, 340), rgb(0, 128, 255), e);

	draw_clr(vector2(10, WIN_HEIGHT - 360), rgb(255, 0, 0), e);
	draw_clr(vector2(10, WIN_HEIGHT - 330), rgb(0, 255, 0), e);
	draw_clr(vector2(10, WIN_HEIGHT - 300), rgb(0, 0, 255), e);
	draw_clr(vector2(10, WIN_HEIGHT - 270), rgb(255, 255, 0), e);
	draw_clr(vector2(10, WIN_HEIGHT - 240), rgb(255, 0, 255), e);
	draw_clr(vector2(10, WIN_HEIGHT - 210), rgb(0, 255, 255), e);
	draw_clr(vector2(10, WIN_HEIGHT - 180), rgb(255, 128, 0), e);
	draw_clr(vector2(10, WIN_HEIGHT - 150), rgb(255, 0, 128), e);
	draw_clr(vector2(10, WIN_HEIGHT - 120), rgb(0, 255, 128), e);
	draw_clr(vector2(10, WIN_HEIGHT - 90), rgb(128, 255, 0), e);
	draw_clr(vector2(10, WIN_HEIGHT - 60), rgb(128, 0, 255), e);
	draw_clr(vector2(10, WIN_HEIGHT - 30), rgb(0, 128, 255), e);
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
	mlx_hook(e->win, 17, (1L<<3), close_win, e);	
	mlx_hook(e->win, 6, (1L << 6), get_mouse_pos, e);
	mlx_hook(e->win, 2, (1L<<0), press_key, e);
	mlx_hook(e->win, 3, (1L<<1), up_key, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, update, e);
	mlx_loop(e->mlx);
	return (1);
}
