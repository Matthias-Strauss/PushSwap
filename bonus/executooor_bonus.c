/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:17 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 15:09:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
# FINDING CHEAPEST EXECUTE

-   lower node
-   higher node
-   calc cheapest execute
*/

t_node	*init_cheapest_exec(t_node *head_src, t_node *head_dst)
{
	t_node	*tmp_src;
	t_node	*dst_lower;
	t_node	*dst_higher;
	t_node	*c_node;

	c_node = head_src;
	tmp_src = head_src;
	while (1)
	{
		dst_higher = higher_ind_in_stk(tmp_src->ind, head_dst);
		dst_lower = lower_ind_in_stk(tmp_src->ind, head_dst);
		if (dst_higher != NULL)
			calc_node_c_exec(tmp_src, dst_higher);
		if (dst_lower != NULL)
			calc_node_c_exec(tmp_src, dst_lower);
		if (c_node->c_exe > tmp_src->c_exe)
			c_node = tmp_src;
		tmp_src = tmp_src->next;
		if (tmp_src == head_src)
			break ;
	}
	return (c_node);
}

// 0 = undefined, 1 = both up, 2 = both down,
// 3 = src up dst down, 4 = src down & dst up
// ORDER:
// up up src bigger cost
// up up dst bigger cost
// down down src bigger cost
// down down dst bigger cost

/// @brief Calculates the cost of rotating two stacks and pushing from one to
/// 		the other in order to bring the nodes together.
/// @param src Node from the Source Stack.
/// @param dst Node from the Destination Stack.
void	calc_node_c_exec(t_node *src, t_node *dst)
{
	if (src->c_rot_up >= dst->c_rot_up && src->c_exe > src->c_rot_up + 1)
	{
		src->combination = 1;
		src->c_exe = src->c_rot_up + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_up <= dst->c_rot_up && src->c_exe > dst->c_rot_up + 1)
	{
		src->combination = 1;
		src->c_exe = dst->c_rot_up + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_down >= dst->c_rot_down && src->c_exe > src->c_rot_down + 1)
	{
		src->combination = 2;
		src->c_exe = src->c_rot_down + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_down <= dst->c_rot_down && src->c_exe > dst->c_rot_down + 1)
	{
		src->combination = 2;
		src->c_exe = dst->c_rot_down + 1;
		src->best_pair = dst;
	}
	calc_node_c_exec_continued(src, dst);
}

void	calc_node_c_exec_continued(t_node *src, t_node *dst)
{
	if (src->c_rot_up + dst->c_rot_down + 1 <= src->c_exe)
	{
		src->combination = 3;
		src->c_exe = src->c_rot_up + dst->c_rot_down + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_down + dst->c_rot_up + 1 <= src->c_exe)
	{
		src->combination = 4;
		src->c_exe = src->c_rot_down + dst->c_rot_up + 1;
		src->best_pair = dst;
	}
}

/// @brief Routes an execution to the correct execution functions.
/// @param c_node Cheapest Node to execute.
/// @param env Environment struct.
void	executor_router(t_node *c_node, t_vars *env)
{
	if (env->reverse == 0)
	{
		if (c_node->combination == 1)
			executooor_a_to_b_up(c_node, env);
		else if (c_node->combination == 2)
			executooor_a_to_b_down(c_node, env);
		else if (c_node->combination == 3)
			executooor_a_to_b_updown(c_node, env);
		else if (c_node->combination == 4)
			executooor_a_to_b_downup(c_node, env);
	}
	else if (env->reverse == 1)
	{
		if (c_node->combination == 1)
			executooor_b_to_a_up(c_node, env);
		else if (c_node->combination == 2)
			executooor_b_to_a_down(c_node, env);
		else if (c_node->combination == 3)
			executooor_b_to_a_updown(c_node, env);
		else if (c_node->combination == 4)
			executooor_b_to_a_downup(c_node, env);
	}
}

/// @brief Rotates a stack so that the smallest IND is at the top.
/// @param head Head pointer of the Stack.
void	rot_to_min(t_node **head)
{
	int		i;
	int		j;
	t_node	*tmp;
	t_node	*min_node;

	i = 0;
	j = 0;
	tmp = *head;
	while (tmp->ind != 0)
	{
		tmp = tmp->next;
		i++;
	}
	min_node = tmp;
	while (tmp != *head)
	{
		tmp = tmp->next;
		j++;
	}
	if (i < j)
		while (min_node != *head)
			ra(head);
	else
		while (min_node != *head)
			rra(head);
}
