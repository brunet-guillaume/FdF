/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:01:34 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/25 11:44:02 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
