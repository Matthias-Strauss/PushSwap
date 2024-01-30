/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_low_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:49:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:08 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **astack)
{
	if ((*astack)->order > (*astack)->next->order)
	{
		sa(astack);
		write(1, "sa\n", 3);
	}
}

void	sort_three(t_stack **astack)
{
	if ((*astack)->order > (*astack)->next->order)
	{
		sa(astack);
		write(1, "sa\n", 3);
	}
	if ((*astack)->next->order > (*astack)->next->next->order)
	{
		ra(astack);
		write(1, "ra\n", 3);
	}
	if ((*astack)->order > (*astack)->next->order)
	{
		sa(astack);
		write(1, "sa\n", 3);
	}
}

void	sort_four(t_stack **astack, t_stack **bstack, int argc)
{
	int		min;
	int		max;
	int		i;
	t_stack	*tmp;

	i = 0;
	min = 1;
	max = argc - 1;
	tmp = *astack;
	while (i++ < 4)
	{
		if ((*astack)->order == min || (*astack)->order == max)
			pb(astack, bstack);
		else
			ra(astack);
	}
	sort_three(astack);
	pa(bstack, astack);
}

int	sort_five(t_stack **astack, t_stack **bstack, int argc)
{
	int		min;
	int		max;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *astack;
	// loop can be replaced with hardcoding min and max from argc
	while (tmp != NULL)
	{
		if (tmp->order > min)
			min = tmp->order;
		tmp = tmp->next;
	}
	max = argc - 1;
	while (i++ < 5)
	{
		if ((*astack)->order == min || (*astack)->order == max)
			pb(astack, bstack);
		else
			ra(astack);
	}
	sort_three(astack);
	pa(astack, bstack);
	pa(astack, bstack);
}
