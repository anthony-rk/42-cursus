/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:51:21 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/10 18:51:24 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int get_left_buffer(char const *s1, char const *set)
{
	int		left_buffer;

	left_buffer = 0;


	while (set[i] && s1[i])
	{
		if (s1[left_buffer] == '\0')
			return (0);
		if (*left_ptr == set[i++])
		{
			left_ptr++;
			left_buffer++;
			i = 0;
		}
	}

	return (left_buffer);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*out;
	char const		*left_ptr;
	unsigned long	i;
	int				left_buffer;
	int				right_buffer;
	int				len;

	left_ptr = s1;
	i = 0;
	left_buffer = 0;
	while (set[i] && s1[i])
	{
		if (s1[left_buffer] == '\0')
		{
			out = (char *)malloc(sizeof(char) * (1));
			out[0] = '\0';
			return (out);
		}
		if (*left_ptr == set[i++])
		{
			left_ptr++;
			left_buffer++;
			i = 0;
		}
	}
	len = ft_strlen(s1) - 1;
	right_buffer = 0;
	i = 0;
	while (set[i])
	{
		if (s1[len] == set[i++])
		{
			len--;
			right_buffer++;
			i = 0;
		}
	}
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) - left_buffer - right_buffer + 1));
	if (out != NULL)
	{
		i = 0;
		while (i < ft_strlen(s1) - left_buffer - right_buffer)
		{
			out[i] = s1[i + left_buffer];
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
