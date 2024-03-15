/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:22 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 10:51:42 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 	Checks if all Elements in a Stack are sorted correctly by comparing
/// 		their final position IND values.
/// @param head 		Head pointer of the Stack to be checked.
/// @param arg_count 	Amount of numbers in the Stack.
/// @return 			1 if Stack is sorted correctly.
/// 					0 if not sorted correctly.
int	check_is_sorted(t_node **head, int arg_count)
{
	t_node	*cur_node;
	t_node	*last_node;
	int		i;

	if (*head == NULL)
		exit(write(1, "Error\n", 6));
	cur_node = *head;
	last_node = (*head)->prev;
	i = 1;
	while (cur_node != last_node)
	{
		if (cur_node->ind >= cur_node->next->ind)
			return (0);
		cur_node = cur_node->next;
		i++;
	}
	if (i != arg_count)
		return (0);
	return (1);
}

/// @brief Chooses which sorting Algo to use based on the length of the list.
/// @param env Struct holding all environment variables.
void	sorting_router(t_vars *env)
{
	if (env->argc >= 6)
	{
		w_pb(&env->a, &env->b);
		w_pb(&env->a, &env->b);
		return ;
	}
	if (env->argc == 5)
	{
		sort4(env);
		exit(1);
	}
	else if (env->argc == 4)
	{
		sort3(&env->a);
		rot_to_min(&env->a);
		exit(1);
	}
	else if (env->argc == 3)
	{
		sort2(&env->a);
		rot_to_min(&env->a);
		exit(1);
	}
	else if (env->argc <= 2)
		exit(write(1, "\n", 1));
}

/// @brief Sorts an indexed Stack of 2 Elements.
/// @param head The head pointer to the Stack to be sorted.
void	sort2(t_node **head)
{
	if ((*head)->ind > (*head)->next->ind)
		w_sa(head);
}

/// 123
/// 132
/// 231
/// 213
/// 312
/// 321
/// @brief Sorts an indexed Stack of 3 Elements.
/// @param head The head pointer of the Stack to be sorted.
void	sort3(t_node **head)
{
	if ((*head)->ind < (*head)->next->ind
		&& (*head)->next->ind < (*head)->next->next->ind)
		return ;
	else if ((*head)->ind < (*head)->next->next->ind
		&& (*head)->next->next->ind < (*head)->next->ind)
		w_sa(head);
	else if ((*head)->next->next->ind < (*head)->ind
		&& (*head)->ind < (*head)->next->ind)
		return ;
	else if ((*head)->next->ind < (*head)->ind
		&& (*head)->ind < (*head)->next->next->ind)
		w_sa(head);
	else if ((*head)->ind > (*head)->next->next->ind
		&& (*head)->next->ind < (*head)->next->next->ind)
		return ;
	else if ((*head)->ind > (*head)->next->ind
		&& (*head)->next->ind > (*head)->next->next->ind)
		w_sa(head);
	return ;
}

/// @brief Sorts an indexed Stack of 4 Elements.
/// @param head The head pointer of the Stack to be sorted.
void	sort4(t_vars *env)
{
	while (env->a->ind != 0)
		w_ra(&env->a);
	w_pb(&env->a, &env->b);
	sort3(&env->a);
	while (env->a->ind != 1)
		w_rra(&env->a);
	w_pa(&env->b, &env->a);
}
