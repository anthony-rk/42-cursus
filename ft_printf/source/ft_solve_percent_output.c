/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_percent_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:19:42 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/11 02:19:34 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_percent_handle_width(t_flags *flags)
{
	if (flags->width > 1)
	{
		flags->total_length += (flags->width - 1);
		flags->width++;
		if (flags->zero == 1 && flags->minus != 1)
			while (--flags->width > 1)
				ft_putchar_fd('0', 1);
		else
			while (--flags->width > 1)
				ft_putchar_fd(' ', 1);
	}
}

void			ft_solve_percent_output(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus == 1)
	{
		ft_putchar_fd('%', 1);
		i++;
	}
	ft_percent_handle_width(flags);
	if (flags->minus != 1)
	{
		ft_putchar_fd('%', 1);
		i++;
	}
	flags->total_length += i;
}
