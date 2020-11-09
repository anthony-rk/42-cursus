/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:26:53 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 15:26:57 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    // loop through until find c, return a pointer to it
    char    *ps;
    int len;
    int i;

    len = ft_strlen(s);
    ps = (char *)s;

    i = 0;
	while (i < len + 1) // + 1 to check for the \0 which could be the c argument
	{
        if (ps[i] == (char)c)
            return ((char*)&(s)[i]);
        else
		    i++;
	}
    return (0);
}