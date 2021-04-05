/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:06:44 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:18:29 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_flags(char *p, t_flags *flags)
{
	int i;

	i = 0;
	while (p[i] == '-' || p[i] == '0')
	{
		if (p[i] == '-')
			flags->minus = 1;
		else if (p[i] == '0')
			flags->zero = 1;
		i++;
	}
	return (i);
}
