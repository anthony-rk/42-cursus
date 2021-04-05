/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:07:46 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/10 02:20:11 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_init_flags_struct(void)
{
	t_flags		flags;

	flags.width = 0;
	flags.precision = 0;
	flags.point = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.type = '0';
	flags.total_length = 0;
	return (flags);
}
