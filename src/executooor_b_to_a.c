/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:33:03 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/09 16:12:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			w_rr(&env->b, &env->a);
		while (c_node->best_pair != env->a)
			w_ra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b && c_node->best_pair != env->a->prev)
			w_rr(&env->b, &env->a);
		while (c_node->best_pair != env->a->prev)
			w_ra(&env->a);
	}
	while (c_node != env->b)
		w_rb(&env->b);
	w_pa(&env->b, &env->a);
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
				w_rrr(&env->b, &env->a);
			while (c_node->best_pair != env->a)
				w_rra(&env->a);
		}
		if (c_node->ind > c_node->best_pair->ind)
		{
			while (c_node != env->b && c_node->best_pair != env->a->prev)
				w_rrr(&env->b, &env->a);
			while (c_node->best_pair != env->a->prev)
				w_rra(&env->a);
		}
		while (c_node != env->b)
			w_rrb(&env->b);
		w_pa(&env->b, &env->a);
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
			w_rb(&env->b);
		while (c_node->best_pair != env->a)
			w_rra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b)
			w_rb(&env->b);
		while (c_node->best_pair != env->a->prev)
			w_rra(&env->a);
	}
	w_pa(&env->b, &env->a);
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_downup(t_node *c_node, t_vars *env)
{
	if (c_node->ind < c_node->best_pair->ind)
	{
		while (c_node != env->b)
			w_rrb(&env->b);
		while (c_node->best_pair != env->a)
			w_ra(&env->a);
	}
	if (c_node->ind > c_node->best_pair->ind)
	{
		while (c_node != env->b)
			w_rrb(&env->b);
		while (c_node->best_pair != env->a->prev)
			w_ra(&env->a);
	}
	w_pa(&env->b, &env->a);
}
