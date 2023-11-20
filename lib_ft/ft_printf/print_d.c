/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:02:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:24:50 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_int_sign(t_opt opts, int d)
{
	if (d < 0)
		ft_putchar_fd('-', 1);
	if (opts.plus && d >= 0)
		ft_putchar_fd('+', 1);
	if (opts.space && !opts.plus && d >= 0)
		ft_putchar_fd(' ', 1);
}

size_t	get_int_size(t_opt opts, int d)
{
	size_t	len;
	size_t	sign;

	sign = 0;
	if (opts.space || opts.plus || d < 0)
		sign = 1;
	len = max(ft_intlen(d) + sign, opts.dot + sign);
	len = max(len, opts.width);
	return (len);
}

size_t	calc_size_zero(int d, t_opt opts)
{
	size_t	len;

	len = 0;
	if (opts.plus || opts.space || d < 0)
		len = 1;
	len += ft_intlen(d);
	return (len);
}

size_t	calc_size(int d, t_opt opts)
{
	size_t	len;

	len = 0;
	if (opts.plus || opts.space || d < 0)
		len = 1;
	len += ft_intlen(d);
	if (opts.zero)
		len += opts.width;
	return (len);
}

size_t	print_d(t_opt opts, va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	if (!opts.minus)
		print_c_i(' ', opts.width - max(calc_size(d, opts), opts.dot));
	print_int_sign(opts, d);
	if (opts.zero)
		print_c_i('0', opts.width - calc_size_zero(d, opts));
	if (opts.dot != -1)
		print_c_i('0', opts.dot - ft_intlen(d));
	print_d_num(d);
	if (opts.minus)
		print_c_i(' ', opts.width - max(calc_size(d, opts), opts.dot));
	return (get_int_size(opts, d));
}
