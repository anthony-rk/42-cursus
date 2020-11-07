/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:23:00 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:23:04 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prototype ft_isalpha and ft_isdigit
int		ft_isalpha(int c);
int		ft_isdigit(int c);

int		ft_isalnum(int c)
{

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	// if (ft_isalpha(c) || ft_isdigit(c))
		// return (1);
	else
		return (0);
}