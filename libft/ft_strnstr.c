/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:52 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:50:54 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char		*ps1;
	const char		*ps2;
	unsigned int	i;
	unsigned int	j;

	if (s2[0] == '\0' || s1 == s2)
		return ((char *)(s1));
	ps1 = (char *)s1;
	ps2 = (char *)s2;
	i = 0;
	while (i < len && ps1[i])
	{
		j = 0;
		if (ps1[i] == ps2[j])
		{
			j++;
			while (ps1[i + j] == ps2[j] && (i + j < len))
			{
				if (!ps2[++j])
					return ((char *)&(ps1)[i]);
			}
		}
		i++;
	}
	return (NULL);
}
