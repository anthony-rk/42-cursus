/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:22:42 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/10 17:22:54 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*out;
	unsigned int	i;
	unsigned int	j;
	unsigned int	out_len;

	out_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	out = (char *)malloc(sizeof(char) * (out_len));
	i = 0;
	j = 0;
	if (out != NULL)
	{
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			out[i + j] = s2[j];
			j++;
		}
		out[i + j] = '\0';
	}
	return (out);
}
