/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:01 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:04 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i;
	i = 0;

	char *csrc = (char *)src;
	char *cdst = (char *)dst;

	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
