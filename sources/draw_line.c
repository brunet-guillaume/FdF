/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:23:15 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 16:48:04 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_draw(t_vector3 p1, t_vector3 p2, t_line *l)
{	
	l->dx = abs(p2.x - p1.x);
	l->sx = 1;
	if (p1.x > p2.x)
		l->sx = -1;
	l->dy = -abs(p2.y - p1.y);
	l->sy = 1;
	if (p1.y > p2.y)
		l->sy = -1;
	l->err = l->dx + l->dy;
}

void	draw_line(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env *e)
{
	t_line	l;

	init_draw(p1, p2, &l);
	while (!(p2.x == p1.x && p2.y == p1.y))
	{
		put_pxl(&e->img, p1, clr);
		l.err2 = 2 * l.err;
		if (l.err2 >= l.dy)
		{
			l.err += l.dy;
			p1.x += l.sx;
		}
		if (l.err2 <= l.dx)
		{
			l.err += l.dx;
			p1.y += l.sy;
		}
	}
}
