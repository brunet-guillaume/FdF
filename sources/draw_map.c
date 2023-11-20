/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:22:16 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 17:30:33 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map_x(int x, int y, t_line_infos line, t_env *e)
{
	line.p2 = transform(e->map.pts[y][x + 1], e);
	line.c2 = e->map.clr[y][x + 1];
	draw_line_aa(line, e);
}

void	draw_map_y(int x, int y, t_line_infos line, t_env *e)
{
	line.p2 = transform(e->map.pts[y + 1][x], e);
	line.c2 = e->map.clr[y + 1][x];
	draw_line_aa(line, e);
}

void	draw_ortho(t_env *e)
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
			line.p1 = transform(e->map.pts[y][x], e);
			line.c1 = e->map.clr[y][x];
			if (x + 1 < e->map.x_max)
				draw_map_x(x, y, line, e);
			if (y + 1 < e->map.y_max)
				draw_map_y(x, y, line, e);
			x++;
		}
		y++;
	}
}

int	draw_map(t_env *e)
{
	set_bg(e, rgb(70, 70, 70));
	draw_ortho(e);
	return (1);
}
