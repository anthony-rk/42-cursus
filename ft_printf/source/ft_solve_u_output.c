/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_u_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:18:49 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 03:11:21 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putstr_itoa(unsigned long long num)
{
	if (num > 9)
	{
		ft_putstr_itoa(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num + '0');
}

static void		u_width(t_flags *flags, unsigned long long n, int len, int df)
{
	if (flags->zero == 1 && df == 0)
	{
		if (flags->point != 0)
			while (--flags->width > len)
				ft_putchar_fd(' ', 1);
		if (flags->point == 0)
			while (--flags->width > len)
				ft_putchar_fd('0', 1);
	}
	else
	{
		while (--flags->width > (len + df))
			ft_putchar_fd(' ', 1);
	}
	ft_putnchar('0', df);
	if (flags->point != 1 || n != 0)
		ft_putstr_itoa(n);
}

static void		u_flags(t_flags *flags, unsigned long long n, int len, int df)
{
	int i;

	i = 0;
	if (flags->minus == 1)
	{
		ft_putnchar('0', df);
		if (flags->point != 1 || n != 0)
			ft_putstr_itoa(n);
		if (flags->width > len)
			while (--flags->width > (len + df))
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (flags->width > len)
			u_width(flags, n, len, df);
		else
		{
			ft_putnchar('0', df);
			if (flags->point != 1 || n != 0)
				ft_putstr_itoa(n);
		}
	}
}

void			ft_solve_u_output(t_flags *flags, va_list arg_ptr)
{
	unsigned long long	num;
	int					len;
	int					diff;

	num = (unsigned int)(va_arg(arg_ptr, long long));
	len = ft_nbrlen(num, 10);
	if (flags->point == 1 && num == 0)
		len--;
	diff = flags->precision - len;
	if (diff < 0)
		diff = 0;
	if (flags->width <= flags->precision)
		flags->total_length += diff;
	if (flags->width > len && (flags->width > flags->precision))
	{
		flags->total_length += (flags->width - len);
		flags->width++;
	}
	u_flags(flags, num, len, diff);
	flags->total_length += len;
}
