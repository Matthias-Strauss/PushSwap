/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:33:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/11 18:41:58 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		Deletes and frees the given node and every successor of that
///				node, using the function ’del’ and free(3). Finally, the pointer
///				to the list must be set to NULL.
/// @param lst 	Address of a pointer to a node.
/// @param del  Address of the function used to delete the content of the node.
void	cdl_lstclear(t_node **starting_node)
{
	t_node	*ptr;
	t_node	*tmp;
	t_node	*last_node;

	ptr = *starting_node;
	last_node = (*starting_node)->prev;
	while (ptr != last_node)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	free(ptr);
}

// Function needs to be changed for CIRCULAR LISTS,
// otherwise the whole list will be deleted instead of from the current
// node to the "end" of the list.