/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:33:03 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 15:37:47 by mstrauss         ###   ########.fr       */
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
void	executooor_b_to_a_up(t_exec *exec, t_vars *env)
{
	{
		if (exec->best_src->ind < exec->best_dst->ind)
		{
			while (exec->best_src != env->b && exec->best_dst != env->a)
				w_rr(env->b, env->a);
			while (exec->best_dst != env->a)
				w_ra(env->a);
		}
		if (exec->best_src->ind > exec->best_dst->ind)
		{
			while (exec->best_src != env->b && exec->best_dst != env->a->prev)
				w_rr(env->b, env->a);
			while (exec->best_dst != env->a->prev)
				w_ra(env->a);
		}
		while (exec->best_src != env->b)
			w_rb(env->b);
		w_pa(env->b, env->a);
	}
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_down(t_exec *exec, t_vars *env)
{
	{
		if (exec->best_src->ind < exec->best_dst->ind)
		{
			while (exec->best_src != env->b && exec->best_dst != env->a)
				w_rrr(env->b, env->a);
			while (exec->best_dst != env->a)
				w_rra(env->a);
		}
		if (exec->best_src->ind > exec->best_dst->ind)
		{
			while (exec->best_src != env->b && exec->best_dst != env->a->prev)
				w_rrr(env->b, env->a);
			while (exec->best_dst != env->a->prev)
				w_rra(env->a);
		}
		while (exec->best_src != env->b)
			w_rrb(env->b);
		w_pa(env->b, env->a);
	}
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_downup(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->b)
			w_rrb(env->b);
		while (exec->best_dst != env->a->prev)
			w_ra(env->a);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->b)
			w_rrb(env->b);
		while (exec->best_dst != env->a)
			w_rb(env->a);
	}
	w_pb(env->b, env->a);
}

/// @brief Orders into a ASCENDINGLY sorted stack according to NODE->IND order.
/// @param exec Struct containing the info needed for execution.
/// @param env Environment Struct containing Pointers to the Stacks.
void	executooor_b_to_a_updown(t_exec *exec, t_vars *env)
{
	if (exec->best_src->ind < exec->best_dst->ind)
	{
		while (exec->best_src != env->b)
			w_rb(env->b);
		while (exec->best_dst != env->a->prev)
			w_rra(env->a);
	}
	if (exec->best_src->ind > exec->best_dst->ind)
	{
		while (exec->best_src != env->b)
			w_rb(env->b);
		while (exec->best_dst != env->a)
			w_rra(env->a);
	}
	w_pa(env->b, env->a);
}
