/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_s_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:37:42 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:36:28 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_s_handle_width(t_flags *flags, int len)
{
	if (flags->width > len)
	{
		flags->total_length += (flags->width - len);
		while (flags->width > len)
		{
			ft_putchar_fd(' ', 1);
			--flags->width;
		}
	}
}

static	void	s_handle_string(t_flags *flags, char *out, int len)
{
	if (flags->minus == 1)
		ft_putstr_fd(out, 1);
	ft_s_handle_width(flags, len);
	if (flags->minus != 1)
		ft_putstr_fd(out, 1);
	flags->total_length += len;
	free(out);
	out = NULL;
}

void			ft_solve_s_output(t_flags *flags, va_list arg_ptr)
{
	char	*out;
	char	*tmp;
	int		len;

	len = 0;
	tmp = va_arg(arg_ptr, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (flags->precision == 0 && flags->point == 0)
		out = ft_strdup(tmp);
	else
	{
		out = malloc(sizeof(char) * (flags->precision + 1));
		ft_strlcpy(out, tmp, (flags->precision + 1));
	}
	len = ft_strlen(out);
	s_handle_string(flags, out, len);
}
