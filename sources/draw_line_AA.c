/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_AA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:58:48 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 21:22:09 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	if_steep_draw(t_line_AA l, t_rgb_color clr, t_env e)
{
	while (l.x <= l.xpx2)
	{
		l.p.x = (int)l.intY;
		l.p.y = l.x;
		put_pxl_AA(&e.img, l.p, clr, fPartOfNb(l.intY));
		l.p.x = (int)l.intY - 1;
		put_pxl_AA(&e.img, l.p, clr, rfPartOfNb(l.intY));
		l.intY += l.gradient;
		l.x++;
	}
}

void	if_not_steep_draw(t_line_AA l, t_rgb_color clr, t_env e)
{
	while(l.x <= l.xpx2)
	{
		l.p.x = l.x;
		l.p.y = (int)l.intY;
		put_pxl_AA(&e.img, l.p, clr, fPartOfNb(l.intY));
		l.p.y = (int)l.intY - 1;
		put_pxl_AA(&e.img, l.p, clr, rfPartOfNb(l.intY));
		l.intY += l.gradient;
		l.x++;
	}
}

void	line_AA_init(t_line_AA *l, t_vector3 p1, t_vector3 p2)
{	
	l->dx = p2.x - p1.x;
	l->dy = p2.y - p1.y;
	l->gradient = l->dy / l->dx;
	if (l->dx == 0.0)
		l->gradient = 1;
	l->xpx1 = p1.x;
	l->xpx2 = p2.x;
	l->intY = p1.y;
	l->x = l->xpx1;
}

void	draw_line_AA(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env e)
{
	t_line_AA	l;

	l.steep = 0;
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
		l.steep = 1;
	if (l.steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p1.x > p2.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	line_AA_init(&l, p1, p2);
	if(l.steep)
		if_steep_draw(l, clr, e);
	else
		if_not_steep_draw(l, clr, e);
}
