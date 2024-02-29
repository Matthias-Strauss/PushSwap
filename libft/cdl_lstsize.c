/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:44:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/19 19:18:29 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Counts the number of nodes in a CIRCULAR DOUBLY LINKED LIST.
/// @param head Head pointer to the first element of the list.
/// @return 	Length of the list.
int	cdl_lstsize(t_node **head)
{
	t_node	*first_node;
	t_node	*ptr;
	int		node_count;

	if (head == NULL || *head == NULL)
		return (0);
	first_node = *head;
	ptr = *head;
	node_count = 0;
	if (ptr->next == ptr->prev)
		return (1);
	while (ptr->next != first_node)
	{
		ptr = ptr->next;
		node_count++;
	}
	return (node_count + 1);
}
