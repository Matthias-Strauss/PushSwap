/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:33:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/25 16:56:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node ’new’ at the beginning of the CircularDoublyLinkedLst.
/// @param lst 	Address of a pointer to the first link of a list.
/// @param new 	Address of a pointer to the node to be added to the list.
void	cdl_lstadd_front(t_node **head, t_node *new)
{
	if (*head == NULL)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->prev = (*head)->prev;
		new->next = *head;
		((*head)->prev)->next = new;
		(*head)->prev = new;
		*head = new;
	}
}
