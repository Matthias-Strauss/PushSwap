/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:33:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 16:00:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		Deletes and frees the given node and every successor of that
///				node, using the function ’del’ and free(3). Finally, the pointer
///				to the list must be set to NULL.
/// @param lst 	Address of a pointer to a node.
/// @param del  Address of the function used to delete the content of the node.
void	mem_lstclear(t_mem **lst, void (*del)(void *))
{
	t_mem	*ptr;
	t_mem	*tmp;

	ptr = *lst;
	tmp = ptr;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		mem_lstdelone(tmp, del);
		tmp = ptr;
	}
	*lst = NULL;
}
