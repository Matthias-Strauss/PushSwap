/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_a_to_b_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:31:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 15:04:31 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
STACK FINAL ORDER
____
|  /
| /
|/

*/

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_up(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b->prev)
			rr(&env->a, &env->b);
		while (c_node->best_pair != env->b->prev)
			rb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b)
			rr(&env->a, &env->b);
		while (c_node->best_pair != env->b)
			rb(&env->b);
	}
	while (c_node != env->a)
		ra(&env->a);
	pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_down(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b->prev)
			rrr(&env->a, &env->b);
		while (c_node->best_pair != env->b->prev)
			rrb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b)
			rrr(&env->a, &env->b);
		while (c_node->best_pair != env->b)
			rrb(&env->b);
	}
	while (c_node != env->a)
		rra(&env->a);
	pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_updown(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a)
			ra(&env->a);
		while (c_node->best_pair != env->b->prev)
			rrb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a)
			ra(&env->a);
		while (c_node->best_pair != env->b)
			rrb(&env->b);
	}
	pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_downup(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a)
			rra(&env->a);
		while (c_node->best_pair != env->b->prev)
			rb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a)
			rra(&env->a);
		while (c_node->best_pair != env->b)
			rb(&env->b);
	}
	pb(&env->a, &env->b);
}
