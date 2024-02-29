/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:47:26 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 16:28:42 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 	Resets all the VARs stored in the NODEs
/// 		used to calculate cheapest exec.
/// @param stk The Stack being reset.
void	reset_c_vars(t_node *stk)
{
	t_node	*tmp;

	tmp = stk->next;
	stk->c_rot_up = INT_MAX;
	stk->c_rot_down = INT_MAX;
	stk->c_exe = INT_MAX;
	stk->combination = 0;
	stk->best_pair = NULL;
	while (1)
	{
		stk->c_rot_up = INT_MAX;
		stk->c_rot_down = INT_MAX;
		stk->c_exe = INT_MAX;
		stk->combination = 0;
		stk->best_pair = NULL;
		tmp = tmp->next;
		if (tmp == stk)
			break ;
	}
}

/// @brief Calculates the cheapest rotation to get an element to top of stack.
/// @param head Amount of rotations neededd to move the element to the top.
///				Positive if rotating up, stored in node->c_rot_up.
///				Positive if rotating down, stored in node->c_rot_down.
void	cheapest_rotate_to_top(t_node *head)
{
	int		i;
	int		j;
	t_node	*cur_node;

	i = 0;
	j = 0;
	head->c_rot_up = 0;
	cur_node = head->next;
	if (cur_node == head)
		return ;
	while (cur_node != head)
	{
		cur_node->c_rot_up = ++i;
		cur_node = cur_node->next;
	}
	cur_node = head->prev;
	while (cur_node != head)
	{
		cur_node->c_rot_down = ++j;
		cur_node = cur_node->prev;
	}
	head->c_rot_down = ++j;
}

/// @brief Takes an INDand finds the closest lower Index in another Stack.
/// @param ind 	IND to compare against.
/// @param head Head of the Stack to search in.
/// @return Address of the Node containing the closest lower IND.
/// 		NULL if the Stack doesn't contain a higher IND.
t_node	*lower_ind_in_stk(int ind, t_node *head)
{
	t_node	*lower_ind_node;
	t_node	*tmp;

	lower_ind_node = head;
	tmp = head->next;
	while (tmp != head)
	{
		if ((lower_ind_node->ind < tmp->ind) && tmp->ind < ind)
			lower_ind_node = tmp;
		tmp = tmp->next;
	}
	if (lower_ind_node->ind > ind)
		return (NULL);
	return (lower_ind_node);
}

/// @brief Takes an IND and finds the closest higher IND in another Stack.
/// @param ind 	IND to compare against.
/// @param head Head of the Stack to search in.
/// @return Address of the Node containing the closest higher IND.
/// 		NULL if the Stack doesn't contain a higher IND.
t_node	*higher_ind_in_stk(int ind, t_node *head)
{
	t_node	*higher_ind_node;
	t_node	*tmp;

	higher_ind_node = head;
	tmp = head->next;
	while (tmp != head)
	{
		if ((higher_ind_node->ind > tmp->ind) && tmp->ind > ind)
			higher_ind_node = tmp;
		tmp = tmp->next;
	}
	if (higher_ind_node->ind < ind)
		return (NULL);
	return (higher_ind_node);
}

/// @brief  Calculates the cheapest Sort_Operations needed in order to push it
///			to the correct position in the other Stack for every single element.
/// @param stk_src	The Stack to pop from.
/// @param stk_dst 	the Stack to push to.
void	calc_c_exec(t_node *stk_src, t_node *stk_dst, t_node *best_src,
		t_node *best_dst)
{
	t_node	*cur_node_src;
	t_node	*cur_node_dst;

	cur_node_src = stk_src;
	cur_node_dst = stk_dst;
	best_src = stk_src;
	while (1)
	{
		while (1)
		{
			cur_node_src->c_exe = node3calc(cur_node_src,
					higher_ind_in_stk(cur_node_src->ind, stk_dst), best_dst);
			if (best_src->c_exe > cur_node_src->c_exe)
			{
				best_src = cur_node_src;
				best_dst = cur_node_dst;
			}
			cur_node_dst = cur_node_dst->next;
			if (cur_node_dst == stk_dst)
				break ;
		}
		cur_node_src = cur_node_src->next;
		if (cur_node_src == stk_src)
			break ;
	}
}

/// @brief 	Takes a Node from Stack1 and compares it to the next higher & lower
///			index nodes in Stack 2, calculating the cheapest overall execute of
/// 		pushing the Node from Stack 1 to Stack 2 in the appropriate position
/// @param src 		The Node from Stack 1.
/// @param low_ind 	The Node from Stack 2 with the closes lower IND.
/// @param high_ind The Node from Stack 2 with the closes higher IND.
/// @return The minimum amount of Stack Operations needed to push from stk 1to2.
///			Regardless of rotation or revers rotation, both are represented as a
/// 		positive value.
int	node3calc(t_node *src, t_node *high_ind, t_node *best_dst)
{
	int	r;
	int	rr;

	if (src->c_rot_up < high_ind->c_rot_up)
		r = high_ind->c_rot_up + 1;
	else
		r = src->c_rot_up + 1;
	if (r > (src->c_rot_up + high_ind->c_rot_down) + 1)
		r = src->c_rot_up + high_ind->c_rot_down + 1;
	if (src->c_rot_down > high_ind->c_rot_down)
		rr = high_ind->c_rot_down + 1;
	else
		rr = src->c_rot_down + 1;
	if (rr < high_ind->c_rot_up + src->c_rot_down)
		rr = high_ind->c_rot_up + src->c_rot_down;
	best_dst = high_ind;
	if (rr < r)
		return (rr);
	else
		return (r);
}

// **FIND THE CORRECT POSITION:**

// - we only insert above the `biggest num < current num`
// - find closest smaller number
//     - `if (cur_num < num to be pushed && cur_num > biggest_smaller_num)`
// - rotate Stack_B so that:
//     - biggest smaller num @top

// CHEAPEST EXECUTE SUPPORT FUNCTIONS

// - lower_ind_in_stk								✓
// - higher_ind_in_stk								✓
// - calc_operation_amount()						✓
//		- take 3 nodes, 1 in a, 2 in b 				✓
//		- calc double rotations & total operations 	✓
//		- store in node struct 						✓
// - build_output_str_ops()							x

// LOGIC
// find lower & higher IND node in other stack -> returns(*t_node)
// calc operations -> saves into cur_ele of src_stk (c_exe)
// 	- include double ops in calc
// execute least operations node
// build output str
// - add output str to output LL
// repeat

// CALCULATE AND WRITE ALL VALUES FOR IN BETWEEN OPERATIONS
// - c_rot
// - c_exe