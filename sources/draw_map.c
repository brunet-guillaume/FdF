/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:22:16 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 11:39:39 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_parallel(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->map.y_max)
	{
		x = 0;
		while (x < e->map.x_max)
		{
			if (x + 1 < e->map.x_max)
			{
				if (e->custom_clr)
					draw_line_AA(parallel_tr(e->map.pts[y][x], e),
						parallel_tr(e->map.pts[y][x + 1], e),
						e->map.clr[y][x], e->map.clr[y][x + 1], e);
				else
					draw_line_AA(parallel_tr(e->map.pts[y][x], e),
						parallel_tr(e->map.pts[y][x + 1], e),
						clr_from_z(e->map.pts[y][x].z, e),
						clr_from_z(e->map.pts[y][x + 1].z, e), e);
			}
			if (y + 1 < e->map.y_max)
			{
				if (e->custom_clr)
					draw_line_AA(parallel_tr(e->map.pts[y][x], e),
						parallel_tr(e->map.pts[y + 1][x], e),
						e->map.clr[y][x], e->map.clr[y + 1][x], e);
				else
					draw_line_AA(parallel_tr(e->map.pts[y][x], e),
						parallel_tr(e->map.pts[y + 1][x], e),
						clr_from_z(e->map.pts[y][x].z, e),
						clr_from_z(e->map.pts[y + 1][x].z, e), e);
			}
			x++;
		}
		y++;
	}
}

int draw_map(t_env *e)
{
	int	x;
	int	y;
	
	set_bg(e, rgb(70, 70, 70));
	if (e->parallel)
	{
		draw_parallel(e);
		return (1);
	}
	y = 0;
	while (y < e->map.y_max)
	{
		x = 0;
		while (x < e->map.x_max)
		{
			if (x + 1 < e->map.x_max)
			{
				if (e->custom_clr)
					draw_line_AA(transform(e->map.pts[y][x], e),
						transform(e->map.pts[y][x + 1], e),
						e->map.clr[y][x], e->map.clr[y][x + 1], e);
				else	
					draw_line_AA(transform(e->map.pts[y][x], e),
						transform(e->map.pts[y][x + 1], e),
						clr_from_z(e->map.pts[y][x].z, e),
						clr_from_z(e->map.pts[y][x + 1].z, e), e);
			}
			if (y + 1 < e->map.y_max)
			{
				if (e->custom_clr)
					draw_line_AA(transform(e->map.pts[y][x], e),
						transform(e->map.pts[y + 1][x], e),
						e->map.clr[y][x], e->map.clr[y + 1][x], e);
				else	
					draw_line_AA(transform(e->map.pts[y][x], e),
						transform(e->map.pts[y + 1][x], e),
						clr_from_z(e->map.pts[y][x].z, e),
						clr_from_z(e->map.pts[y + 1][x].z, e), e);
			}
			x++;
		}
		y++;
	}
	return (1);
}
