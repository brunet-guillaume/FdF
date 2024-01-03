/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_converter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:05:23 by gbrunet           #+#    #+#             */
/*   Updated: 2024/01/03 13:41:26 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_rgb_color	rgb_from_int(int clr)
{
	t_rgb_color	converted_clr;

	converted_clr.r = (clr >> 16 & 0xFF);
	converted_clr.g = (clr >> 8 & 0xFF);
	converted_clr.b = (clr & 0xFF);
	return (converted_clr);
}

int	int_from_rgb(t_rgb_color clr)
{
	int	r;
	int	g;
	int	b;

	r = min(max(clr.r, 0), 255) << 16;
	g = min(max(clr.g, 0), 255) << 8;
	b = min(max(clr.b, 0), 255);
	return (r + g + b);
}

t_rgb_color	clr_from_z(int z, t_env *e)
{
	t_rgb_color	clr;
	float		coef;

	coef = (z - e->map.z_min) / (float)(e->map.z_max - e->map.z_min);
	clr = lerp_clr(e->clr_bottom, e->clr_top, coef);
	return (clr);
}

t_rgb_color	char_to_rgb(char *clr)
{
	t_rgb_color	rgb_clr;

	if (ft_strlen(clr) == 8)
	{
		rgb_clr.r = hex_val(clr[2]) * 16 + hex_val(clr[3]);
		rgb_clr.g = hex_val(clr[4]) * 16 + hex_val(clr[5]);
		rgb_clr.b = hex_val(clr[6]) * 16 + hex_val(clr[7]);
	}
	else if (ft_strlen(clr) == 6)
	{
		rgb_clr.r = 0;
		rgb_clr.g = hex_val(clr[2]) * 16 + hex_val(clr[3]);
		rgb_clr.b = hex_val(clr[4]) * 16 + hex_val(clr[5]);
	}
	else if (ft_strlen(clr) == 4)
	{
		rgb_clr.r = 0;
		rgb_clr.g = 0;
		rgb_clr.b = hex_val(clr[2]) * 16 + hex_val(clr[3]);
	}
	else
		rgb_clr = rgb(256, 256, 256);
	return (rgb_clr);
}
