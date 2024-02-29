/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:31:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 15:38:00 by mstrauss         ###   ########.fr       */
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
void	executooor_a_to_b_up(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->a && exec->best_dst != env->b->prev)
			w_rr(env->a, env->b);
		while (exec->best_dst != env->b->prev)
			w_rb(env->b);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->a && exec->best_dst != env->b)
			w_rr(env->a, env->b);
		while (exec->best_dst != env->b)
			w_rb(env->b);
	}
	while (exec->best_src != env->a)
		w_ra(env->a);
	w_pb(env->a, env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_down(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->a && exec->best_dst != env->b->prev)
			w_rrr(env->a, env->b);
		while (exec->best_dst != env->b->prev)
			w_rrb(env->b);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->a && exec->best_dst != env->b)
			w_rrr(env->a, env->b);
		while (exec->best_dst != env->b)
			w_rrb(env->b);
	}
	while (exec->best_src != env->a)
		w_rra(env->a);
	w_pb(env->a, env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_updown(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->a)
			w_ra(env->a);
		while (exec->best_dst != env->b->prev)
			w_rrb(env->b);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->a)
			w_ra(env->a);
		while (exec->best_dst != env->b)
			w_rrb(env->b);
	}
	w_pb(env->a, env->b);
}

/// @brief Orders into a DESCENDINGLY sorted stacks according to NODE->IND order
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_a_to_b_downup(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->a)
			w_rra(env->a);
		while (exec->best_dst != env->b->prev)
			w_rb(env->b);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->a)
			w_rra(env->a);
		while (exec->best_dst != env->b)
			w_rb(env->b);
	}
	w_pb(env->a, env->b);
}
