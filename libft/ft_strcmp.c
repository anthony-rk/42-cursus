/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:33 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:35 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
		if (!s1[i] && !s2[i])
			return (0);
	}
	return (s1[i] - s2[i]);
}
