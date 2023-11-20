/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:04:33 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 16:06:37 by gbrunet          ###   ########.fr       */
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

int	mix_color(t_rgb_color clr, float bright, int back_clr)
{
	t_rgb_color	b_rgb;
	int			r;
	int			g;
	int			b;

	b_rgb = rgb_from_int(back_clr);
	r = min(max(b_rgb.r * (1 - bright) + bright * clr.r, 0), 255) << 16;
	g = min(max(b_rgb.g * (1 - bright) + bright * clr.g, 0), 255) << 8;
	b = min(max(b_rgb.b * (1 - bright) + bright * clr.b, 0), 255);
	return (r + g + b);
}

t_rgb_color	lerp_clr(t_rgb_color clr1, t_rgb_color clr2, float t)
{
	t_rgb_color	clr;

	clr.r = clr1.r * (1 - t) + clr2.r * t;
	clr.g = clr1.g * (1 - t) + clr2.g * t;
	clr.b = clr1.b * (1 - t) + clr2.b * t;
	return (clr);
}

int	hex_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (ft_toupper(c) >= 'A' && ft_toupper(c) <= 'F')
		return (c - 'A' + 10);
	return (-1);
}
