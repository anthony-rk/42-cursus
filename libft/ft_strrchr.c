/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:39:53 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/06 16:39:57 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
    // loop through until find c, return a pointer to it
    char    *ps;
    int len;

    len = ft_strlen(s);
    ps = (char *)s;

    len++; // + 1 to check for the \0 which could be the c argument
	while (len--)
	{
        if (ps[len] == (char)c)
            return ((char*)&(s)[len]);
	}
    return (0);
}