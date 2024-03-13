/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:34:33 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 13:32:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ######################
// # DOUBLE OPERATIONS  #
// ######################

/// @brief Swaps the top 2 elements of both Stacks using one Operation.
/// @param a_head Head pointer of the First Stack.
/// @param b_head Head pointer of the Second Stack.
void	ss(t_node **a_head, t_node **b_head)
{
	swap(a_head);
	swap(b_head);
}

/// @brief Rotates both Stacks using one Operation.
/// @param a_head Head pointer of the first Stack.
/// @param b_head Head pointer of the second Stack.
void	rr(t_node **a_head, t_node **b_head)
{
	rot(a_head);
	rot(b_head);
}

/// @brief Reverse Rotates both Stacks using one Operation.
/// @param a_head Head pointer of the first Stack.
/// @param b_head Head pointer of the second Stack.
void	rrr(t_node **a_head, t_node **b_head)
{
	rev_rot(a_head);
	rev_rot(b_head);
}
