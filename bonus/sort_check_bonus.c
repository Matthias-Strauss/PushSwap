/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:05:27 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 15:05:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/// @brief 	Checks if all Elements in a Stack are sorted correctly by comparing
/// 		their final position IND values.
/// @param head 		Head pointer of the Stack to be checked.
/// @param arg_count 	Amount of numbers in the Stack.
/// @return 			1 if Stack is sorted correctly.
/// 					0 if not sorted correctly.
int	check_is_sorted(t_node **head, int arg_count)
{
	t_node	*cur_node;
	int		i;

	if (*head == NULL)
		exit(write(1, "Error\n", 6));
	cur_node = (*head)->next;
	i = 1;
	while (cur_node != *head)
	{
		if (cur_node->ind >= cur_node->next->ind)
			return (0);
		cur_node = cur_node->next;
		i++;
	}
	if (i != arg_count)
		return (0);
	return (1);
}
