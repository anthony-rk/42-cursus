/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:00:22 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:16:23 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_analyze_input(char *p, t_flags *flags, va_list arg_ptr)
{
	int		i;

	i = 0;
	i += ft_check_flags(&p[i], flags);
	i += ft_check_width(&p[i], flags, arg_ptr);
	i += ft_check_precis(&p[i], flags, arg_ptr);
	i += ft_check_conversion_char(&p[i], flags);
	ft_solver_base(flags, arg_ptr);
}
