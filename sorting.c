/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:22 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/29 15:48:50 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
	int		i;

	if (*head == NULL)
		exit(write(1, "Error\n", 6));
	cur_node = (*head)->next;
	i = 1;
	while (cur_node != *head)
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
	if (env->argc >= 5)
	{
		w_pb(&env->a, &env->b);
		w_pb(&env->a, &env->b);
		return ;
	}
	else if (env->argc == 4)
		sort3(&env->a);
	else if (env->argc == 3)
		sort2(&env->a);
	else if (env->argc <= 2)
		exit(write(1, "\n", 1));
}

/// @brief Sorts an indexed Stack of 2 Elements.
/// @param head The head pointer to the Stack to be sorted.
void	sort2(t_node **head)
{
	if ((*head)->num > (*head)->next->num)
		swap(head);
}

/// @brief Sorts an indexed Stack of 3 Elements.
/// @param head The head pointer of the Stack to be sorted.
void	sort3(t_node **head)
{
	if ((*head)->num > (*head)->next->num)
		swap(head);
	if ((*head)->next->num > (*head)->next->next->num)
		rot(head);
	if ((*head)->num > (*head)->next->num)
		swap(head);
}

/// @brief Sorting Algorithm for sorting a list (>3ele) of INTs using two Stacks
/// @param env Struct holding all important environment variables.
void	sort_big(t_vars *env)
{
	t_exec	exec;

	if (env->reverse == 0)
	{
		calc_c_exec(env->a, env->b, exec.best_src, exec.best_dst);
		execute(&exec, &env->a, &env->b);
	}
	else if (env->reverse == 1)
	{
		calc_c_exec(env->b, env->a, exec.best_src, exec.best_dst);
		execute(&exec, &env->b, &env->a);
	}
}
