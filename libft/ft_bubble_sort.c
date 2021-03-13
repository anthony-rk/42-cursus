/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:28:19 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/09 14:31:22 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_ints(int *x_ptr, int *y_ptr )
{
	int		tmp;
	
	tmp = *x_ptr;
	*x_ptr = *y_ptr;
	*y_ptr = tmp;
}

void	ft_bubble_sort(int arr[], int n)
{
	int i;
	int j;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - i - 1))
		{
			if (arr[j] > arr[j + 1])
				ft_swap_ints(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}