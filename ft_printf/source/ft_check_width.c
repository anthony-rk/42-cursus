/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:06:00 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:19:32 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_width(char *p, t_flags *flags, va_list arg_ptr)
{
	int	i;

	i = 0;
	if (p[i] == '*')
	{
		flags->width = va_arg(arg_ptr, int);
		if (flags->width < 0)
		{
			flags->width = flags->width * -1;
			flags->minus = 1;
		}
		i++;
	}
	if (ft_isdigit(p[i]))
	{
		flags->width = ft_atoi(&p[i]);
		i++;
	}
	while (ft_isdigit(p[i]))
		i++;
	return (i);
}
