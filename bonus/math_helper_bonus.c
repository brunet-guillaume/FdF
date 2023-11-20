/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:01:34 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 17:57:50 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

float	fpartofnb(float x)
{
	if (x > 0)
		return (x - (int)x);
	return (x - ((int)x + 1));
}

float	rfpartofnb(float x)
{
	return (1 - fpartofnb(x));
}

int	toggle(int i)
{
	if (i == 1)
		return (0);
	return (1);
}
