/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_b_to_a_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:33:03 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 15:04:38 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
STACK FINAL ORDER

|\
| \
|__\

*/

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_up(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->b && c_node->best_pair != env->a)
			rr(&env->b, &env->a);
		while (c_node->best_pair != env->a)
			ra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b && c_node->best_pair != env->a->prev)
			rr(&env->b, &env->a);
		while (c_node->best_pair != env->a->prev)
			ra(&env->a);
	}
	while (c_node != env->b)
		rb(&env->b);
	pa(&env->b, &env->a);
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_down(t_node *c_node, t_vars *env)
{
	{
		if (c_node->ind < c_node->best_pair->ind)
		{
			while (c_node != env->b && c_node->best_pair != env->a)
				rrr(&env->b, &env->a);
			while (c_node->best_pair != env->a)
				rra(&env->a);
		}
		if (c_node->ind > c_node->best_pair->ind)
		{
			while (c_node != env->b && c_node->best_pair != env->a->prev)
				rrr(&env->b, &env->a);
			while (c_node->best_pair != env->a->prev)
				rra(&env->a);
		}
		while (c_node != env->b)
			rrb(&env->b);
		pa(&env->b, &env->a);
	}
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_updown(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->b)
			rb(&env->b);
		while (c_node->best_pair != env->a)
			rra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b)
			rb(&env->b);
		while (c_node->best_pair != env->a->prev)
			rra(&env->a);
	}
	pa(&env->b, &env->a);
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_downup(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->b)
			rrb(&env->b);
		while (c_node->best_pair != env->a)
			ra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b)
			rrb(&env->b);
		while (c_node->best_pair != env->a->prev)
			ra(&env->a);
	}
	pa(&env->b, &env->a);
}
