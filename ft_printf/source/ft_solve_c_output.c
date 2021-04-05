/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_c_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:33:41 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:27:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_c_handle_width(t_flags *flags)
{
	if (flags->width > 1)
	{
		flags->total_length += (flags->width - 1);
		flags->width++;
		if (flags->zero == '1' && flags->minus != '1')
			while (--flags->width > 1)
				ft_putchar_fd('0', 1);
		else
			while (--flags->width > 1)
				ft_putchar_fd(' ', 1);
	}
}

void			ft_solve_c_output(t_flags *flags, va_list arg_ptr)
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(arg_ptr, int);
	if (flags->minus == 1)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	ft_c_handle_width(flags);
	if (flags->minus != 1)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	flags->total_length += i;
}
