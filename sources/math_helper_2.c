/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:54:49 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 17:59:56 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	d_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	d_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

t_vector2	vector2(int x, int y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}
