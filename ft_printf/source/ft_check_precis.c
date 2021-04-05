/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:15 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:10:28 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_precis(char *p, t_flags *flags, va_list arg_ptr)
{
	int	i;

	i = 0;
	if (p[0] == '.')
	{
		flags->point = 1;
		i++;
		if (p[i] == '*')
		{
			flags->precision = va_arg(arg_ptr, int);
			if (flags->precision < 0)
			{
				flags->precision = 0;
				flags->point = 0;
			}
			i++;
		}
		if (ft_isdigit(p[i]))
			flags->precision = ft_atoi(&p[i]);
		while (ft_isdigit(p[i]))
			i++;
		if (flags->precision > 2)
			flags->point = 2;
	}
	return (i);
}
