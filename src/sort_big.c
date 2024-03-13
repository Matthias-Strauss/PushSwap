/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:58:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/13 10:58:30 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorting Algorithm for sorting a list (>3ele) of INTs using two Stacks
/// @param env Struct holding all important environment variables.
void	sort_big(t_vars *env)
{
	t_node	*c_node;

	if (env->reverse == 0)
	{
		c_node = init_cheapest_exec(env->a, env->b);
		executor_router(c_node, env);
	}
	else if (env->reverse == 1)
	{
		c_node = init_cheapest_exec(env->b, env->a);
		executor_router(c_node, env);
	}
}
