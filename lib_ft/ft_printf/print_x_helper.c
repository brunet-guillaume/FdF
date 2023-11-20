/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:48:20 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:52:34 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	x_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb / 16)
	{
		nb /= 16;
		len++;
	}
	return (len + 1);
}

size_t	calc_x_size(unsigned int x, t_opt opts)
{
	size_t	len;

	len = 0;
	len += x_len(x);
	if (opts.zero)
		len += opts.width;
	return (len);
}
