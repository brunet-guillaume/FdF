/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:04:33 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 10:13:01 by gbrunet          ###   ########.fr       */
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

t_rgb_color	lerp_clr(t_rgb_color clr1, t_rgb_color clr2, float t)
{
	t_rgb_color	clr;

	clr.r = clr1.r * (1 - t) + clr2.r * t;
	clr.g = clr1.g * (1 - t) + clr2.g * t;
	clr.b = clr1.b * (1 - t) + clr2.b * t;
	return (clr);
}

t_rgb_color clr_from_z(int z, t_env *e)
{
	t_rgb_color	clr;
	float		coef;
	coef = (z - e->map.z_min) / (float)(e->map.z_max - e->map.z_min);
	clr = lerp_clr(e->clr_bottom, e->clr_top, coef);
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

t_rgb_color char_to_rgb(char *clr)
{
	t_rgb_color	rgb; 
	
	rgb.r = hex_val(clr[2]) * 16 + hex_val(clr[3]);
	rgb.g = hex_val(clr[4]) * 16 + hex_val(clr[5]);
	rgb.b = hex_val(clr[6]) * 16 + hex_val(clr[7]);
	return (rgb);
}
