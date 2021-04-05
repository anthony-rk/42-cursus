/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_xx_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:19:01 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 03:03:54 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putstr_hex_itoa(unsigned long long n, char format)
{
	if (n > 15)
	{
		ft_putstr_hex_itoa(n / 16, format);
		ft_putstr_hex_itoa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

static void		x_flags(t_flags *flags, unsigned long long n, int len, int df)
{
	flags->width++;
	if (flags->minus == 1)
	{
		ft_putnchar('0', df);
		if (flags->point != 1 || n != 0)
			ft_putstr_hex_itoa(n, flags->type);
		if (flags->width > len)
			while (--flags->width > (len + df))
				ft_putchar(' ');
	}
	else
	{
		if (flags->width > len && (flags->zero != 1 || flags->point != 0))
			while (--flags->width > (len + df))
				ft_putchar(' ');
		if (flags->width > len && flags->zero == 1 && flags->point == 0)
			while (--flags->width > (len + df))
				ft_putchar('0');
		ft_putnchar('0', df);
		if (flags->point != 1 || n != 0)
			ft_putstr_hex_itoa(n, flags->type);
	}
}

void			ft_solve_xx_output(t_flags *flags, va_list arg_ptr)
{
	unsigned long long	num;
	unsigned long long	tmp;
	int					num_len;
	int					diff;

	num = (unsigned int)va_arg(arg_ptr, unsigned long long);
	tmp = num;
	num_len = 0;
	if (tmp == 0 && flags->point != 1)
		num_len++;
	while (tmp > 0)
	{
		num_len++;
		tmp /= 16;
	}
	diff = flags->precision - (num_len);
	if (diff < 0)
		diff = 0;
	if (flags->width <= flags->precision && diff != 0)
		flags->total_length += diff;
	if (flags->width > num_len && flags->width > flags->precision)
		flags->total_length += (flags->width - num_len);
	x_flags(flags, num, num_len, diff);
	flags->total_length += num_len;
}
