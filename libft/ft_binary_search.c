/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:48:41 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/14 12:30:36 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_binary_search(int arr[], int lft, int rt, int x)
{
	int mid;

	while (lft <= rt)
	{
		mid = (lft + rt) / 2;

		// find the middle, if middle == x return that index, else recurse on either left or right half
		if (arr[mid] == x)
			return (mid);
		else
		{
			if (arr[mid] < x) // recurse on the right half
				return (ft_binary_search(arr, mid + 1, rt, x));
			if (arr[mid] > x) // recurse on the left half
				return (ft_binary_search(arr, lft, mid - 1, x));
		}
	}
	return (-1); // Not found in the array
}