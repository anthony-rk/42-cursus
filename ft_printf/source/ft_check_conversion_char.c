/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:04:02 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:17:39 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_conversion_char(char *p, t_flags *flags)
{
	int i;

	i = 0;
	if (p[i] == 'c')
		flags->type = 'c';
	else if (p[i] == 's')
		flags->type = 's';
	else if (p[i] == 'p')
		flags->type = 'p';
	else if (p[i] == 'd' || p[i] == 'i')
		flags->type = 'd';
	else if (p[i] == 'u')
		flags->type = 'u';
	else if (p[i] == 'x')
		flags->type = 'x';
	else if (p[i] == 'X')
		flags->type = 'X';
	else if (p[i] == '%')
		flags->type = '%';
	else
		return (0);
	i++;
	return (i);
}
