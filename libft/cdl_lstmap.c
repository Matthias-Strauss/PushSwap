/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:56:30 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/27 16:09:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on the
///				content of each node. Creates a new list resulting of the
///				successive applications of the function ’f’. The ’del’ function
///				is used to delete the content of a node if needed.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
/// @param del 	The address of the function used to delete
///				the content of a node if needed.
/// @return 	The new list. NULL if the allocation fails.
t_node	*cdl_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*lstnew;
	t_node	*lstnext;
	void	*data;

	// t_node	*first_node;
	lstnext = NULL;
	if (lst == NULL)
		return (NULL);
	lstnext = cdl_lstmap(lst->next, *f, *del);
	data = f(lst->best_pair);
	lstnew = cdl_lstnew(lst->num);
	if (lstnew == NULL)
	{
		del(data);
		cdl_lstclear(&lstnext, del);
		return (NULL);
	}
	lstnew->next = lstnext;
	return (lstnew);
}
