/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:50:40 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 18:07:37 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on
///				the content of each node.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
void	cdl_lstiter(t_node **head, void (*f)(void *))
{
	t_node	*cur_node;

	cur_node = *head;
	while (cur_node->next != *head)
	{
		f(cur_node->prev);
		cur_node = cur_node->next;
	}
	f(&(cur_node->c_exe));
}

// 	Need to adjust to general purpose CDL-List,
//	currently built for push_swap config