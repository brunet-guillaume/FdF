/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:13:43 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:20:14 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_p_hex(unsigned long nb)
{
	if (nb >= 16)
	{
		print_p_hex(nb / 16);
		print_p_hex(nb % 16);
	}
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	else if (nb < 16)
		ft_putchar_fd('a' + nb - 10, 1);
}

size_t	p_len(unsigned long nb)
{
	size_t	len;

	len = 0;
	while (nb / 16)
	{
		nb /= 16;
		len++;
	}
	return (len + 3);
}

size_t	print_p(t_opt opts, va_list *ap)
{
	void	*p;
	size_t	len;

	p = va_arg(*ap, void *);
	len = p_len((unsigned long)p);
	if (!opts.minus)
		print_c_i(' ', opts.width - len);
	ft_putstr_fd("0x", 1);
	print_p_hex((unsigned long)p);
	if (opts.minus)
		print_c_i(' ', opts.width - len);
	return (max(len, opts.width));
}
