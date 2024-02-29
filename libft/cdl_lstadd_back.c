/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:19:36 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 18:06:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Adds the node NEW at the end of the CIRCULAR DOUBLY LINKED LIST
/// @param lst 	Address of a pointer to the first link of a list.
/// @param new	Address of a pointer to the node to be added to the list.
void	cdl_lstadd_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (*head == NULL)
	{
		*head = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		tmp = cdl_lstlast(head);
		tmp->next = new;
		new->next = *head;
		new->prev = tmp;
		(*head)->prev = new;
	}
}
