/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:18:32 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:35:27 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_putnbr(long long nbr)
{
	if (nbr < 0)
		ft_putnbr(nbr * -1);
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar_fd(('0' + nbr), 1);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

static void		di_width(t_flags *flags, long long num, int len, int diff)
{
	if (flags->zero == 1 && diff == 0)
	{
		if (flags->point != 0)
			while (--flags->width > len)
				ft_putchar_fd(' ', 1);
		if (num < 0)
			ft_putchar_fd('-', 1);
		if (flags->point == 0)
			while (--flags->width > len)
				ft_putchar_fd('0', 1);
	}
	else
	{
		while (--flags->width > (len + diff))
			ft_putchar_fd(' ', 1);
		if (num < 0)
			ft_putchar_fd('-', 1);
	}
	ft_putnchar('0', diff);
	if (flags->point != 1 || num != 0)
		ft_putnbr(num);
}

static void		di_handle_flags(t_flags *flags, int num, int len, int diff)
{
	if (flags->minus == 1)
	{
		if (num < 0)
			ft_putchar_fd('-', 1);
		ft_putnchar('0', diff);
		if (flags->point != 1 || num != 0)
			ft_putnbr(num);
		if (flags->width > len)
			while (--flags->width > (len + diff))
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (flags->width > len)
			di_width(flags, num, len, diff);
		else
		{
			if (num < 0)
				ft_putchar_fd('-', 1);
			ft_putnchar('0', diff);
			if (flags->point != 1 || num != 0)
				ft_putnbr(num);
		}
	}
}

void			ft_solve_di_output(t_flags *flags, va_list arg_ptr)
{
	long long	num;
	int			len;
	int			diff;

	num = (int)(va_arg(arg_ptr, long long));
	len = ft_nbrlen(num, 10);
	if (flags->point == 1 && num == 0)
		len--;
	diff = flags->precision - len;
	if (num < 0)
		len++;
	if (diff < 0)
		diff = 0;
	if (flags->width <= flags->precision)
		flags->total_length += diff;
	if (flags->width > len && (flags->width > flags->precision))
	{
		flags->total_length += (flags->width - len);
		flags->width++;
	}
	di_handle_flags(flags, num, len, diff);
	flags->total_length += len;
}
