/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:34:43 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/30 12:16:26 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Converts strings into doubles.
/// @param argc
/// @param argv
/// @param astack
/// @return Amount of converted strings.
int	parse_args(int argc, char *argv[], t_stack **astack)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		new = ps_stacknew(ps_atod(argv[i]));
		ps_stackadd_back(&*astack, new);
		i++;
	}
	return (i - 1);
}

/// @brief Checks the parameters of the stack for duplicates & negative numbers.
/// @param stack Stack to be checked.
/// @return	Amount of errors found.
int	validate_params(t_stack **stack)
{
	t_stack	*current;
	t_stack	*rest;
	int		cnt;

	cnt = 0;
	current = *stack;
	while (current != NULL)
	{
		rest = current->next;
		while (rest != NULL)
		{
			if (current->value == rest->value || current->value > INT_MAX
				|| current->value < INT_MIN)
			{
				cnt++;
				write(2, "Error\n", 6);
				break ;
			}
			rest = rest->next;
		}
		current = current->next;
	}
	return (cnt);
}

/// @brief Outputs the contents of stack A and B in stdout.
/// @param astack Stack A.
/// @param bstack Stack B.
void	memdbg(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *astack;
	tmp_b = *bstack;
	pf_printf("########\n--------\nStack A:\n--------\n");
	while ((*tmp_a).next != NULL)
	{
		pf_printf("%d\n", (*tmp_a).value);
		tmp_a = tmp_a->next;
	}
	pf_printf("%d\n", (*tmp_a).value);
	pf_printf("--------\nStack B:\n--------\n");
	while (tmp_b && tmp_b->next != NULL)
	{
		pf_printf("%d\n", (*tmp_b).value);
		tmp_b = tmp_b->next;
	}
	if (tmp_b)
		pf_printf("%d\n", (*tmp_b).value);
	else
		pf_printf("Empty\n--------\n");
}

/// @brief Takes a stack of integers and indexes them in ascending order.
/// @param astack Stack to be sorted.
/// @param count Amount of integers in the stack.
void	pre_sort(t_stack **astack, int count)
{
	t_stack	*current;
	t_stack	*tmp;
	t_stack	*highestnode;
	int		highestval;

	current = *astack;
	while (count > 0)
	{
		tmp = *astack;
		highestval = 0;
		highestnode = NULL;
		count--;
		while (tmp != NULL)
		{
			if (tmp->order == 0 && tmp->value > highestval)
			{
				highestval = (tmp->value);
				highestnode = tmp;
			}
			tmp = tmp->next;
		}
		if (highestnode == NULL)
			break ;
		highestnode->order = count;
	}
}

int	sort_router(t_stack **astack, t_stack **bstack, int argc)
{
	t_stack	*tmp;
	int		i;
	char	*initial_order;

	i = 0;
	tmp = *astack;
	initial_order = malloc(sizeof(char) * argc);
	while (tmp != NULL)
	{
		initial_order[i] = (char)tmp->order;
		tmp = tmp->next;
		i++;
	}
	if (argc > 5)
		return (sort5hardcode(astack, bstack, argc));
	else if (argc == 5)
		return (sort4hardcode(initial_order));
	else if (argc == 4)
		return (sort3hardcode(initial_order));
	else if (argc == 3)
		return (sort2hardcode(initial_order));
	else
		return ;
}

/// @brief Main of the program PushSwap. Takes a list of integers to sort.
/// @param argc	Amount of integers (+1)
/// @param argv storage of integers
/// @return NULL
int	main(int argc, char *argv[])
{
	t_stack	*astk_head;
	t_stack	*bstk_head;

	astk_head = NULL;
	bstk_head = NULL;
	parse_args(argc, argv, &astk_head);
	validate_params(&astk_head);
	pre_sort(&astk_head, argc);
	memdbg(&astk_head, &bstk_head);
	if (argc >= 5)
		sort_k(&astk_head, &bstk_head, argc);
	else
		sort_router(&astk_head, &bstk_head, argc);
	return (0);
}
