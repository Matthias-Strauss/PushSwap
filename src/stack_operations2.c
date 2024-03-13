/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:19:45 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 22:44:11 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Reverse Rotates a Stack.
/// @param head Head Pointer of the Stack to be reverse rotated.
void	rev_rot(t_node **head)
{
	if (*head != NULL)
		*head = (*head)->prev;
}
