/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:24:41 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:24:43 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char 	*out;
	int 	len;
	size_t 	i;

	len = ft_strlen(s1);

	out = (char *)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		out[i] = s1[i];
		i++;
	}
	return (out);
}
