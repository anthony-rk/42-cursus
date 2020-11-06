/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:22:34 by akowalsk          #+#    #+#             */
/*   Updated: 2020/10/31 14:22:36 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This uses the malloc function
// The calloc() function contiguously allocates enough space for count objects
// that are size bytes of memory each and returns a pointer to the allocated
// memory.  The allocated memory is filled with bytes of value zero.

#include "libft.h"

// void	*ft_memset(void *ptr, int c, size_t len)
// {
// 	unsigned int index;
// 	unsigned char *memory;
// 	int *value;

// 	index = 0;
// 	memory = ptr;
// 	value = &c;	

// 	if (len == 0)
// 	{
// 		return (ptr);
// 	}
// 	while (index < len)
// 	{
// 		memory[index] = c;
// 		index++;
// 	}
// 	return (memory);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;

    if (!(out = malloc(size * count)))
        return (NULL);
    ft_memset(out, 0, count * size);
	return (out);
}
