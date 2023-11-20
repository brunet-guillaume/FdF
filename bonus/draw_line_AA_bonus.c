/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_AA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:58:48 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/20 08:40:26 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

void	if_steep_draw(t_line_aa l, t_line_infos line, t_env *e)
{
	float	coef;
	int		gap;

	gap = l.xpx2 - l.x;
	while (l.x <= l.xpx2)
	{
		coef = 1 - (l.xpx2 - l.x) / (float)gap;
		l.p.x = (int)l.int_y;
		l.p.y = l.x;
		put_pxl_aa(&e->img, l.p, lerp_clr(line.c1, line.c2, coef),
			fpartofnb(l.int_y));
		l.p.x = (int)l.int_y - 1;
		put_pxl_aa(&e->img, l.p, lerp_clr(line.c1, line.c2, coef),
			rfpartofnb(l.int_y));
		l.int_y += l.gradient;
		l.x++;
	}
}

void	if_not_steep_draw(t_line_aa l, t_line_infos line, t_env *e)
{
	float	coef;
	int		gap;

	gap = l.xpx2 - l.x;
	while (l.x <= l.xpx2)
	{
		coef = 1 - (l.xpx2 - l.x) / (float)gap;
		l.p.x = l.x;
		l.p.y = (int)l.int_y;
		put_pxl_aa(&e->img, l.p, lerp_clr(line.c1, line.c2, coef),
			fpartofnb(l.int_y));
		l.p.y = (int)l.int_y - 1;
		put_pxl_aa(&e->img, l.p, lerp_clr(line.c1, line.c2, coef),
			rfpartofnb(l.int_y));
		l.int_y += l.gradient;
		l.x++;
	}
}

void	line_aa_init(t_line_aa *l, t_line_infos line)
{	
	l->dx = line.p2.x - line.p1.x;
	l->dy = line.p2.y - line.p1.y;
	l->gradient = l->dy / l->dx;
	if (l->dx == 0.0)
		l->gradient = 1;
	l->xpx1 = line.p1.x;
	l->xpx2 = line.p2.x;
	l->int_y = line.p1.y;
	l->x = l->xpx1;
}

void	get_clr(t_line_infos *line, t_env *e)
{
	if (line->c1.r == 256)
		line->c1 = e->clr_bottom;
	if (line->c2.r == 256)
		line->c2 = e->clr_bottom;
}

void	draw_line_aa(t_line_infos line, t_env *e)
{
	t_line_aa	l;
	t_rgb_color	temp;

	l.steep = 0;
	if (abs(line.p2.y - line.p1.y) > abs(line.p2.x - line.p1.x))
		l.steep = 1;
	if (l.steep)
	{
		swap(&line.p1.x, &line.p1.y);
		swap(&line.p2.x, &line.p2.y);
	}
	if (line.p1.x > line.p2.x)
	{
		temp = line.c1;
		line.c1 = line.c2;
		line.c2 = temp;
		swap(&line.p1.x, &line.p2.x);
		swap(&line.p1.y, &line.p2.y);
	}
	line_aa_init(&l, line);
	get_clr(&line, e);
	if (l.steep)
		if_steep_draw(l, line, e);
	else
		if_not_steep_draw(l, line, e);
}
