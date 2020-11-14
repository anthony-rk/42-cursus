/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:00:36 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/11 19:00:39 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			get_num_words(char const *s, char c)
{
	unsigned int words;

	words = 0;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
		{
			words++;
			s++;
		}
		s++;
	}
	if (*s == '\0' && *(s - 1) != c)
		words++;
	return (words);
}

static unsigned int			get_next_word_len(const char *s, char c)
{
	unsigned int	i;

	if (*s == c)
		s++;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

char						**ft_split(char const *s, char c)
{
	char			**split_result;
	unsigned int	num_strings;
	unsigned int	i;
	unsigned int	next_str_len;
	char			*next_str;

	if (!s)
		return (NULL);
	num_strings = get_num_words(s, c);
	split_result = (char **)malloc(sizeof(char *) * (num_strings + 1));
	if (!split_result)
		return (NULL);
	i = 0;
	next_str_len = 0;
	next_str = (char *)s;
	while (i < num_strings)
	{
		while (*next_str == c)
			next_str++;
		next_str_len = get_next_word_len(next_str, c);
		split_result[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!split_result[i])
			return (NULL);
		ft_strlcpy(split_result[i], next_str, next_str_len + 1);
		i++;
		next_str += next_str_len + 1;
	}
	split_result[i] = NULL;
	return (&*split_result);
}
