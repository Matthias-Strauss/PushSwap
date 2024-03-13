/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:07:52 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/11 19:04:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Takes a stack of integers and indexes them in ascending final_index.
/// @param head Stack to be sorted.
/// @param count Amount of integers in the stack.
void	indexing(t_node **head, int count)
{
	t_node	*tmp;
	t_node	*highestnode;
	int		highestval;

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
		highestnode->ind = count;
	}
}
