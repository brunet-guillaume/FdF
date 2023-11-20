/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:00:51 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 18:09:09 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_top(int y, t_env *e)
{
	if (y >= 10 && y <= 30)
		e->clr_top = rgb(255, 0, 0);
	else if (y >= 40 && y <= 60)
		e->clr_top = rgb(0, 255, 0);
	else if (y >= 70 && y <= 90)
		e->clr_top = rgb(0, 0, 255);
	else if (y >= 100 && y <= 120)
		e->clr_top = rgb(255, 255, 0);
	else if (y >= 130 && y <= 150)
		e->clr_top = rgb(255, 0, 255);
	else if (y >= 160 && y <= 180)
		e->clr_top = rgb(0, 255, 255);
	else if (y >= 190 && y <= 210)
		e->clr_top = rgb(255, 128, 0);
	else if (y >= 220 && y <= 240)
		e->clr_top = rgb(255, 0, 128);
	else if (y >= 250 && y <= 270)
		e->clr_top = rgb(0, 255, 128);
	else if (y >= 280 && y <= 300)
		e->clr_top = rgb(128, 255, 0);
	else if (y >= 310 && y <= 330)
		e->clr_top = rgb(128, 0, 255);
	else if (y >= 340 && y <= 360)
		e->clr_top = rgb(0, 128, 255);
}

void	check_bottom(int y, t_env *e)
{
	if (y >= WIN_HEIGHT - 360 && y <= WIN_HEIGHT - 340)
		e->clr_bottom = rgb(255, 0, 0);
	else if (y >= WIN_HEIGHT - 330 && y <= WIN_HEIGHT - 310)
		e->clr_bottom = rgb(0, 255, 0);
	else if (y >= WIN_HEIGHT - 300 && y <= WIN_HEIGHT - 280)
		e->clr_bottom = rgb(0, 0, 255);
	else if (y >= WIN_HEIGHT - 270 && y <= WIN_HEIGHT - 250)
		e->clr_bottom = rgb(255, 255, 0);
	else if (y >= WIN_HEIGHT - 240 && y <= WIN_HEIGHT - 220)
		e->clr_bottom = rgb(255, 0, 255);
	else if (y >= WIN_HEIGHT - 210 && y <= WIN_HEIGHT - 190)
		e->clr_bottom = rgb(0, 255, 255);
	else if (y >= WIN_HEIGHT - 180 && y <= WIN_HEIGHT - 160)
		e->clr_bottom = rgb(255, 128, 0);
	else if (y >= WIN_HEIGHT - 150 && y <= WIN_HEIGHT - 130)
		e->clr_bottom = rgb(255, 0, 128);
	else if (y >= WIN_HEIGHT - 120 && y <= WIN_HEIGHT - 100)
		e->clr_bottom = rgb(0, 255, 128);
	else if (y >= WIN_HEIGHT - 90 && y <= WIN_HEIGHT - 70)
		e->clr_bottom = rgb(128, 255, 0);
	else if (y >= WIN_HEIGHT - 60 && y <= WIN_HEIGHT - 40)
		e->clr_bottom = rgb(128, 0, 255);
	else if (y >= WIN_HEIGHT - 30 && y <= WIN_HEIGHT - 10)
		e->clr_bottom = rgb(0, 128, 255);
}

void	check_click(int x, int y, t_env *e)
{
	if (x >= 10 && x <= 30)
	{
		check_top(y, e);
		check_bottom(y, e);
	}
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
