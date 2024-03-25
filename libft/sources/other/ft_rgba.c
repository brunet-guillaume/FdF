/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:15:25 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/22 15:54:00 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clr	rgba_from_int(int clr)
{
	t_clr	out_clr;

	out_clr.a = 255 - (clr >> 24 & 0xFF);
	out_clr.r = (clr >> 16 & 0xFF);
	out_clr.g = (clr >> 8 & 0xFF);
	out_clr.b = (clr & 0xFF);
	out_clr.rgba = clr;
	return (out_clr);
}

t_clr	rgba(int r, int g, int b, int a)
{
	t_clr	out_clr;

	out_clr.a = 255 - clamp(a, 0, 255);
	out_clr.r = clamp(r, 0, 255);
	out_clr.g = clamp(g, 0, 255);
	out_clr.b = clamp(b, 0, 255);
	out_clr.rgba = (((255 - out_clr.a) << 24) + (out_clr.r << 16)
			+ (out_clr.g << 8) + out_clr.b);
	return (out_clr);
}
