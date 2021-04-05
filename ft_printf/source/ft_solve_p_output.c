/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_p_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:18:21 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 03:02:12 by akowalsk         ###   ########.fr       */
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
		{
			ft_putchar(n + '0');
		}
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

static void		p_handle_width(t_flags *flags, int address_len, int diff)
{
	if (flags->width > address_len && flags->width > flags->precision)
	{
		flags->total_length += (flags->width - address_len);
		flags->width++;
		if (flags->zero == 1 && flags->minus != 1 && diff != 0)
			while (--flags->width > address_len)
				ft_putchar('0');
		else
			while (--flags->width > (address_len + diff))
				ft_putchar(' ');
	}
}

static void		p_flags(t_flags *flags, unsigned long long add, int len, int df)
{
	if (flags->minus == 1 || (flags->zero == 1 && df == 0))
	{
		ft_putstr_fd("0x", 1);
		ft_putnchar('0', df);
	}
	if (flags->minus == 1 && (add != 0 || flags->point != 1))
	{
		ft_putstr_hex_itoa(add, 'x');
	}
	p_handle_width(flags, len, df);
	if (flags->minus != 1 && (flags->zero != 1 || df != 0))
	{
		ft_putstr_fd("0x", 1);
		if (add == 0)
			df = 1;
		ft_putnchar('0', df);
	}
	if (flags->minus != 1 && (add != 0 && flags->point != 1))
	{
		ft_putstr_hex_itoa(add, 'x');
	}
}

void			ft_solve_p_output(t_flags *flags, va_list arg_ptr)
{
	unsigned long long	address;
	unsigned long long	tmp;
	int					address_len;
	int					diff;

	address = (unsigned long long)va_arg(arg_ptr, void *);
	address_len = 2;
	tmp = address;
	if (tmp == 0)
		address_len++;
	else
	{
		while (tmp > 0)
		{
			address_len++;
			tmp /= 16;
		}
	}
	diff = flags->precision - (address_len + 2);
	if (diff < 0)
		diff = 0;
	if (flags->width <= flags->precision && diff != 0)
		flags->total_length += diff;
	p_flags(flags, address, address_len, diff);
	flags->total_length += address_len;
}
