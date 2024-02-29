/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:07:52 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 15:54:28 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Takes a stack of integers and indexes them in ascending final_index.
/// @param head Stack to be sorted.
/// @param count Amount of integers in the stack.
void	indexing(t_node **head, int count)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*highestnode;
	int		highestval;

	current = *head;
	while (count > 0)
	{
		tmp = *head;
		highestval = INT_MIN;
		highestnode = NULL;
		count--;
		while (1)
		{
			if (tmp->ind == 0 && tmp->num > highestval)
			{
				highestval = (tmp->num);
				highestnode = tmp;
			}
			tmp = tmp->next;
			if (tmp == *head)
				break ;
		}
		if (highestnode == NULL)
			break ;
		highestnode->ind = count;
	}
}

// /// @brief Finds the MAX "ind" value in a Stack
// ///        implemented using a circular doubly linked list.
// /// @param head Head pointer of the Stack to be analyzed.
// /// @return The MAX IND.
// int	max_ind_stack(t_node *head)
// {
// 	int		max;
// 	t_node	*cur_node;

// 	max = head->ind;
// 	cur_node = head->next;
// 	while (cur_node != head)
// 	{
// 		if (cur_node->ind > max)
// 			max = cur_node->ind;
// 		cur_node = cur_node->next;
// 	}
// 	return (max);
// }

// /// @brief Finds the MIN "ind" value in a Stack
// ///        implemented using a circular doubly linked list.
// /// @param head Head pointer of the Stack to be analyzed.
// /// @return The MIN IND.
// int	min_ind_stack(t_node *head)
// {
// 	int		min;
// 	t_node	*cur_node;

// 	min = head->ind;
// 	cur_node = head->next;
// 	while (cur_node != head)
// 	{
// 		if (cur_node->ind < min)
// 			min = cur_node->ind;
// 		cur_node = cur_node->next;
// 	}
// 	return (min);
// }
