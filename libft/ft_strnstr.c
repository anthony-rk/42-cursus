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
    // loop through until find c, return a pointer to it
    char    *ps1;
    char    *ps2;

    size_t i;
    int j;

    ps1 = (char *)s1;
    ps2 = (char *)s2;

    i = 0;
    
    if (ps2[i] == '\0')
        return ((char*)&(ps1)[i]);
    
	while (i < len && ps1[i])
	{
        j = 0;
        if (ps1[i] == ps2[j])
        {
            j++;
            while (ps1[i + j] == ps2[j] && (i + j < len))
            {
                j++;
                if (!ps2[j])
                    return ((char*)&(ps1)[i]);
            }
        }
        i++;
	}
    return (NULL);
}