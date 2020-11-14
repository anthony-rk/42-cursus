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

static unsigned int    get_num_words(char const *s, char c)
{
    unsigned int words;

    words = 0;
    while (*s)
    {
        if (*s == c)
        {
            words++;
            s++;
        }
        s++;
    }
    if (*s == '\0')
      words++;
    return (words);
}

static unsigned int		get_next_word_len(const char *s, char c, unsigned int i)
{
	// loop over s from i until it hits c, then return the diff between i and c, the strlen so to speak
	unsigned int	start;

	start = i;
	while (s[i])
	{
		if (s[i] == c)
			break;
		i++;
	}
	return (i - start);
}

char                    **ft_split(char const *s, char c)
{
    char            **split_result;
    unsigned int    num_strings;
    unsigned int    i;
    unsigned int    next_str_len;
    char            *next_str;

    if (!s)
        return (NULL);
    
    num_strings = get_num_words(s, c);

    split_result = (char **)malloc(sizeof(char *) * (num_strings + 1));

    if (!split_result)
        return (NULL);

    // Loop over the s string, find the length of the string, then strlcpy() with malloc()

    i = 0;
    next_str_len = 0;
    next_str = (char *)s;
    while (i < num_strings)
    {
        // get next word function,
		
		// Issue where this len is too long by +1
        next_str_len = get_next_word_len(next_str, c, next_str_len);

        // Issue with this line below
        split_result[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));

        if (!split_result[i])
            return (NULL);

        // copy the string over to split_result[j]
		if (i != 0)
			next_str += next_str_len;
        ft_strlcpy(split_result[i], next_str, next_str_len + 1);
        i++;
    }
    split_result[i] = NULL;
    return (&*split_result);
}