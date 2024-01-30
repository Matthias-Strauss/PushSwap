/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_swap_push.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:33:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:11 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **astack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *astack;
	second = (*astack)->next;
	third = second->next;
	if (first == NULL || second == NULL)
		return ;
	first->next = third;
	second->next = first;
	*astack = second;
	pf_printf("sa\n");
	return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **bstack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *bstack;
	second = (*bstack)->next;
	third = second->next;
	if (first == NULL || second == NULL)
		return ;
	first->next = third;
	second->next = first;
	*bstack = second;
	pf_printf("sb\n");
	return ;
}

// ss : sa and sb at the same time.
void	ss(t_stack **astack, t_stack **bstack)
{
	sa(astack);
	sb(bstack);
	pf_printf("ss\n");
	return ;
}

// pa (push a) Take the first element at the top of b and put it at the top of a
// Do nothing if b is empty.
void	pa(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp;

	if (*bstack == NULL)
		return ;
	tmp = *bstack;
	*bstack = (*bstack)->next;
	tmp->next = *astack;
	*astack = tmp;
	pf_printf("pa\n");
	return ;
}

// pb (push b)Take the first element at the top of a and put it at the top of b
// Do nothing if a is empty
void	pb(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp;

	if (*astack == NULL)
		return ;
	tmp = *astack;
	*astack = (*astack)->next;
	tmp->next = *bstack;
	*bstack = tmp;
	pf_printf("pb\n");
	return ;
}
