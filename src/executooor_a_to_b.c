/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:31:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/08 15:02:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			w_rr(&env->a, &env->b);
		while (c_node->best_pair != env->b->prev)
			w_rb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b)
			w_rr(&env->a, &env->b);
		while (c_node->best_pair != env->b)
			w_rb(&env->b);
	}
	while (c_node != env->a)
		w_ra(&env->a);
	w_pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_down(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b->prev)
			w_rrr(&env->a, &env->b);
		while (c_node->best_pair != env->b->prev)
			w_rrb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a && c_node->best_pair != env->b)
			w_rrr(&env->a, &env->b);
		while (c_node->best_pair != env->b)
			w_rrb(&env->b);
	}
	while (c_node != env->a)
		w_rra(&env->a);
	w_pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_updown(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a)
			w_ra(&env->a);
		while (c_node->best_pair != env->b->prev)
			w_rrb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a)
			w_ra(&env->a);
		while (c_node->best_pair != env->b)
			w_rrb(&env->b);
	}
	w_pb(&env->a, &env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_downup(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->a)
			w_rra(&env->a);
		while (c_node->best_pair != env->b->prev)
			w_rb(&env->b);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->a)
			w_rra(&env->a);
		while (c_node->best_pair != env->b)
			w_rb(&env->b);
	}
	w_pb(&env->a, &env->b);
}
