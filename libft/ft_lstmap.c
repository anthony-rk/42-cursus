/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:54:48 by akowalsk          #+#    #+#             */
/*   Updated: 2020/11/18 20:54:50 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	// Can just copy the list, then run the function with ft_lstiter
	// t_list			*lst_temp;
	t_list			*new_node;
	// t_list			*old_head;
	t_list			*new_list;

	if (!lst || !f)
		return (NULL);


	// old_head = lst; // to know where to delete the old list
	if (!(new_node = ft_lstnew(f(lst->content))))
	{
		// need to delete list if it fails
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_list = new_node;
	lst = lst->next;

	while (lst)
	{
		// new_node = new_node->next;
		if (!(new_node = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, new_node); // Start this on the second Node
	}
	return (new_list);
}
