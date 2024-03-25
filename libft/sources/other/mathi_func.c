/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathi_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:08:56 by gbrunet           #+#    #+#             */
/*   Updated: 2024/02/22 15:45:20 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	clamp(int nb, int a, int b)
{
	if (a < b)
		return (max(min(b, nb), a));
	else
		return (max(min(a, nb), b));
}
