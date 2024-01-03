/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallel_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:27:59 by gbrunet           #+#    #+#             */
/*   Updated: 2024/01/03 13:36:05 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_parallel_x(int x, int y, t_line_infos line, t_env *e)
{
	line.p2 = parallel_tr(e->map.pts[y][x + 1], e);
	if (e->custom_clr)
	{
		if (x + 2 < e->map.x_max)
			line.c2 = e->map.clr[y][x + 1];
		else
			line.c2 = e->map.clr[y][x];
		draw_line_aa(line, e);
	}
	else
	{
		line.c1 = clr_from_z(e->map.pts[y][x].z, e);
		line.c2 = clr_from_z(e->map.pts[y][x + 1].z, e);
		draw_line_aa(line, e);
	}
}

void	draw_parallel_y(int x, int y, t_line_infos line, t_env *e)
{
	line.p2 = parallel_tr(e->map.pts[y + 1][x], e);
	if (e->custom_clr)
	{
		if (x + 1 < e->map.x_max)
			line.c2 = e->map.clr[y + 1][x];
		else
		{
			line.c1 = e->map.clr[y][x - 1];
			line.c2 = e->map.clr[y + 1][x - 1];
		}
		draw_line_aa(line, e);
	}
	else
	{
		line.c1 = clr_from_z(e->map.pts[y][x].z, e);
		line.c2 = clr_from_z(e->map.pts[y + 1][x].z, e);
		draw_line_aa(line, e);
	}
}

void	draw_parallel(t_env *e)
{
	int				x;
	int				y;
	t_line_infos	line;

	y = 0;
	while (y < e->map.y_max)
	{
		x = 0;
		while (x < e->map.x_max)
		{
			line.p1 = parallel_tr(e->map.pts[y][x], e);
			line.c1 = e->map.clr[y][x];
			if (x + 1 < e->map.x_max)
				draw_parallel_x(x, y, line, e);
			if (y + 1 < e->map.y_max)
				draw_parallel_y(x, y, line, e);
			x++;
		}
		y++;
	}
}
