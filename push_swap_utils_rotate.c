/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:16:03 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **astack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*astack == NULL || (*astack)->next == NULL)
		return ;
	first = *astack;
	second = (*astack)->next;
	last = ps_stacklast(astack);
	first->next = NULL;
	last->next = first;
	*astack = second;
	pf_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **bstack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*bstack == NULL || (*bstack)->next == NULL)
		return ;
	first = *bstack;
	second = (*bstack)->next;
	last = ps_stacklast(bstack);
	first->next = NULL;
	last->next = first;
	*bstack = second;
	pf_printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_stack **astack, t_stack **bstack)
{
	ra(astack);
	rb(bstack);
	pf_printf("rr\n");
}
