/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:04:33 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 21:57:36 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_rgb_color	rgb(int r, int g, int b)
{
	t_rgb_color	clr;

	clr.r = r;
	clr.g = g;
	clr.b = b;
	return (clr);
}

t_rgb_color rgb_from_int(int clr)
{
	t_rgb_color	converted_clr;

	converted_clr.r = (clr >> 16 & 0xFF);
	converted_clr.g = (clr >> 8 & 0xFF);
	converted_clr.b = (clr & 0xFF);
	return (converted_clr);
}

int int_from_rgb(t_rgb_color clr)
{
	int r;
	int g;
	int b;

	r = min(max(clr.r, 0), 255) << 16;
	g = min(max(clr.g, 0), 255) << 8;
	b = min(max(clr.b, 0), 255);
	return (r + g + b);
}

int	mix_color(t_rgb_color clr, float bright, int back_clr)
{
	t_rgb_color b_rgb;
	int			r;
	int			g;
	int			b;

	b_rgb = rgb_from_int(back_clr);
	r = min(max(b_rgb.r * (1 - bright) + bright * clr.r, 0), 255) << 16;
	g = min(max(b_rgb.g * (1 - bright) + bright * clr.g, 0), 255) << 8;
	b = min(max(b_rgb.b * (1 - bright) + bright * clr.b, 0), 255);
	return (r + g + b);
}
