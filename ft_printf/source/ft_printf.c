/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:27:49 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:23:25 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_move_past_conversion(char *str)
{
	int len;

	len = 0;
	while (str[len] != 'c' && str[len] != 's' && str[len] != 'p'
			&& str[len] != 'd' && str[len] != 'i' && str[len] != 'u'
			&& str[len] != 'x' && str[len] != 'X' && str[len] != '%')
		len++;
	return (len + 1);
}

static void	ft_reset_flags_struct(t_flags *flags)
{
	flags->width = 0;
	flags->precision = 0;
	flags->point = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->type = '0';
}

int			ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	t_flags		flags;
	char		*p;

	p = (char *)format;
	flags = ft_init_flags_struct();
	va_start(arg_ptr, format);
	while (*p)
	{
		while (*p != '%' && *p != '\0')
		{
			ft_putchar_fd(*p++, 1);
			flags.total_length++;
		}
		if (*p == '%')
		{
			ft_analyze_input(++p, &flags, arg_ptr);
			p += ft_move_past_conversion(p);
			ft_reset_flags_struct(&flags);
		}
	}
	va_end(arg_ptr);
	return (flags.total_length);
}
