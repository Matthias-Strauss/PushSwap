/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:47:26 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 22:05:56 by mstrauss         ###   ########.fr       */
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
		tmp->c_rot_up = INT_MAX;
		tmp->c_rot_down = INT_MAX;
		tmp->c_exe = INT_MAX;
		tmp->combination = 0;
		tmp->best_pair = NULL;
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
		if (((lower_ind_node->ind < tmp->ind) && tmp->ind < ind)
			|| lower_ind_node->ind > ind)
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
		if (((higher_ind_node->ind > tmp->ind) && tmp->ind > ind)
			|| higher_ind_node->ind < ind)
			higher_ind_node = tmp;
		tmp = tmp->next;
	}
	if (higher_ind_node->ind < ind)
		return (NULL);
	return (higher_ind_node);
}
