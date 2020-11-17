/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:32:01 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/14 15:32:15 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char    *ft_itoa_zero()
{
    char    *out;

    if (!(out = (char *)malloc(sizeof(char) * (2))))
        return (NULL);

    out[0] = '0';
    out[1] = '\0';

    return (out);
}

static unsigned int        ft_num_len(int n)
{
    unsigned int    len;

    len = 0;
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char            *out;
    int             sign;
    unsigned int    len;
    unsigned int    n_temp;

    len = 0;
    sign = 1;

    n_temp = (n < 0 ? -n : n);
    len = ft_num_len(n_temp);
    if (n < 0)
    {
        sign = -1;
        len++;
    }

    if (n == 0)
        return (ft_itoa_zero());
    if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);

    out[len--] = '\0';
    while (n_temp)
    {
        out[len] = '0' + (n_temp % 10);
        len--;
        n_temp /= 10;
    }
    if (sign < 0)
        out[len] = '-';

    return (out);
}

// static int			ft_nblen(unsigned int n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (n >= 10)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	return (i + 1);
// }

// char				*ft_itoa(int n)
// {
// 	char			*dest;
// 	unsigned int	len;
// 	unsigned int	nb;
// 	unsigned int	i;

// 	nb = (n < 0 ? -n : n);
// 	len = ft_nblen(nb);
// 	i = 0;
// 	if (!(dest = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		dest[i] = '-';
// 		len++;
// 	}
// 	i = len - 1;
// 	while (nb >= 10)
// 	{
// 		dest[i] = nb % 10 + 48;
// 		nb /= 10;
// 		i--;
// 	}
// 	dest[i] = nb % 10 + 48;
// 	dest[len] = '\0';
// 	return (dest);
// }