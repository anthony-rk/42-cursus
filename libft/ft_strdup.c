/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:01:10 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:01:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char 	*out;
	int 	len;
	int 	i;

	len = ft_strlen(s1);

	out = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		out[i] = s1[i];
		i++;
	}
	return (out);
}