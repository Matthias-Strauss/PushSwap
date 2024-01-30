/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:17:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/15 18:33:40 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **astack)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ps_stacklast(astack);
	second_last = ps_stacklast(astack)->next;
	last->next = NULL;
	second_last->next = *astack;
	*astack = last;
	pf_printf("rra\n");
	return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **bstack)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ps_stacklast(bstack);
	second_last = ps_stacklast(bstack)->next;
	last->next = NULL;
	second_last->next = *bstack;
	*bstack = last;
	pf_printf("rrb\n");
	return ;
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack **astack, t_stack **bstack)

{
	rra(astack);
	rrb(bstack);
	pf_printf("rrr\n");
	return ;
}
