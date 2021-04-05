/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:23 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:14:02 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_solver_base(t_flags *flags, va_list arg_ptr)
{
	if (flags->type == 'c')
		ft_solve_c_output(flags, arg_ptr);
	else if (flags->type == 's')
		ft_solve_s_output(flags, arg_ptr);
	else if (flags->type == 'p')
		ft_solve_p_output(flags, arg_ptr);
	else if (flags->type == 'd' || flags->type == 'i')
		ft_solve_di_output(flags, arg_ptr);
	else if (flags->type == 'u')
		ft_solve_u_output(flags, arg_ptr);
	else if (flags->type == 'x' || flags->type == 'X')
		ft_solve_xx_output(flags, arg_ptr);
	else if (flags->type == '%')
		ft_solve_percent_output(flags);
	else
	{
		ft_putstr_fd("[[--ERROR INVALID CONVERSION TYPE--]]", 1);
	}
}
