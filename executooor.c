/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executooor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:17 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 18:03:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
# FINDING CHEAPEST EXECUTE

-   lower node
-   higher node
-   calc cheapest execute
*/

// void	calc_rev_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
// void	calc_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
// void	calc_rev_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
// void	calc_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
// t_node	*higher_ind_in_stk(int ind, t_node *head);
// t_node	*lower_ind_in_stk(int ind, t_node *head);

void	init_cheapest_exec(t_node **head_src, t_node **head_dst, t_exec exec)
{
	t_node	*tmp_src;
	t_node	*dst_lower;
	t_node	*dst_higher;

	tmp_src = head_src;
	while (1)
	{
		dst_higher = higher_ind_in_stk(tmp_src->ind, *head_dst);
		dst_lower = lower_ind_in_stk(tmp_src->ind, *head_dst);
		if (dst_higher != NULL)
			calc_node_c_exec(tmp_src, dst_lower);
		if (dst_lower != NULL)
			calc_node_c_exec(tmp_src, dst_higher);
		tmp_src = tmp_src->next;
		if (tmp_src == head_src)
			break ;
	}
}

// Rewrite to per node instead of building in exec????????
void	calc_node_c_exec(t_node *src, t_node *dst)
{
	// CHECK CONDITIONS IF THEY OVERWRITE EACH OTHER (higher vs lower)
	if (src->c_rot_up > dst->c_rot_up)
	{
		src->combination = 1;
		src->c_exe = src->c_rot_up + 1;
		src->best_pair = dst;
	}
	else
	{
		src->combination = 1;
		src->c_exe = dst->c_rot_up + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_down > dst->c_rot_down && src->c_rot_down + 1 < src->c_exe)
	{
		src->combination = 2;
		src->c_exe = src->c_rot_down;
		src->best_pair = dst;
	}
	else if (dst->c_rot_down + 1 < src->c_exe)
	{
		src->combination = 2;
		src->c_exe = dst->c_rot_up + 1;
		src->best_pair = dst;
	}
	calc_node_c_exec_continued(src, dst);
}

void	calc_node_c_exec_continued(t_node *src, t_node *dst)
{
	if (src->c_rot_up + dst->c_rot_down + 1 < src->c_exe)
	{
		src->combination = 3;
		src->c_exe = src->c_rot_up + dst->c_rot_down + 1;
		src->best_pair = dst;
	}
	if (src->c_rot_down + dst->c_rot_up + 1 < src->c_exe)
	{
		src->combination = 4;
		src->c_exe = src->c_rot_down;
		src->best_pair = dst;
	}
}

/*
void	calc_rev_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
void	calc_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
void	calc_rev_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
void	calc_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
t_node	*higher_ind_in_stk(int ind, t_node *head);
t_node	*lower_ind_in_stk(int ind, t_node *head);
if (cur_node->ind > pair_node->ind)					->next smallest IND node
	-> rotate dst to pair_node == head_dst
else												->next biggest IND node
	-> rotate dst to pair_node == head_dst->prev
*/
/// @brief Executes the cheapest calculated move and uses the values stored
/// 		in the exec struct to execute double rotations, leftover rotations,
///			and pushes the top element from stk_src to stk_dst.
/// @param exec 	The struct containing the necessary values for Stack Ops.
/// @param head_src	The head pointer to the Source Stack.
/// @param head_dst The head pointer to the Destination Stack.
// void	execute(t_exec *exec, t_node **head_src, t_node **head_dst)
// {
// 	if (exec->dbl_rot + (exec->rot_dst - exec->dbl_rot) + (exec->rot_src
// 			- exec->dbl_rot) < exec->dbl_rrot + (exec->rrot_dst
// 			- exec->dbl_rrot) + (exec->rrot_src - exec->dbl_rrot))
// 	{
// 		while (exec->dbl_rot-- > 0)
// 			w_rr(head_src, head_dst);
// 		while (exec->rot_src-- > 0)
// 			w_ra(head_src);
// 		while (exec->rot_dst-- > 0)
// 			w_rb(head_src);
// 		w_pa(head_src, head_dst);
// 	}
// 	else
// 	{
// 		while (exec->dbl_rrot-- > 0)
// 			w_rrr(head_src, head_dst);
// 		while (exec->rrot_src > 0)
// 			w_rra(head_src);
// 		while (exec->rrot_dst > 0)
// 			w_rrb(head_src);
// 		w_pb(head_src, head_dst);
// 	}
// }