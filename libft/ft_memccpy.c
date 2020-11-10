/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:23:46 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:23:50 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*psrc;
	char	*pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
	i = 0;
	while (i < n)
	{
		if (psrc[i] == (unsigned char)c)
		{
			pdst[i] = psrc[i];
			return (&(dst)[i + 1]);
		}
		else
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (NULL);
}
