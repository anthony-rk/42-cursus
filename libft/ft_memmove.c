/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:11 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:13 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	char *csrc = (char *)src;
	char *cdst = (char *)dst;

	i = 0;
	if (csrc > cdst)
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			*(csrc++) = *(cdst++);

	return (dst);
}
