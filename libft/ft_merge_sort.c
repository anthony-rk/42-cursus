/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:43:58 by akowalsk          #+#    #+#             */
/*   Updated: 2021/03/09 15:44:00 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_merge_arrays(int arr[], int left, int mid, int right)
{
    int i;
    int j;
    int k;
    int n1;
    int n2;

    i = 0;
    j = 0;
    n1 = mid - left + 1;
    n2 = right - mid;
    
    int l_arr[n1];
    int r_arr[n2];
    while (i < n1)
    {
        l_arr[i] = arr[left + i];
        i++;
    }
    while (j < n2)
    {
        r_arr[j] = arr[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (l_arr[i] <= r_arr[j])
            arr[k] = l_arr[i++];
        else
            arr[k] = r_arr[j++];
        k++;
    }
    while (i < n1)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    } 
}

void	ft_merge_sort(int arr[], int left, int right)
{
    int mid;

    mid = 0;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        ft_merge_sort(arr, left, mid);
        ft_merge_sort(arr, (mid + 1), right);
        ft_merge_arrays(arr, left, mid, right);
    }
}