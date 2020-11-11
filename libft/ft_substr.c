/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:05:34 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/09 21:05:36 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	substr = (char *)malloc(sizeof(char) * (len));
	i = 0;
	if (len == 0)
		return (substr);
	if (substr != NULL)
	{
		while (s[i] && s[i + 1] && len)
		{
			substr[i] = s[start + i];
			i++;
			len--;
		}
		substr[i] = '\0';
	}
	return (substr);
}
