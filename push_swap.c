/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:38:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ALLOWED FUNCTIONS: read, write, malloc, free, exit

#include "push_swap.h"

/// @brief 		Returns the last node of the stack.
/// @param stack 	Beginning of the stack.
/// @return 	Last node of the stack.
t_stack	*ps_stacklast(t_stack **stack)
{
	t_stack	*ptr;

	if (*stack == NULL)
		return (NULL);
	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

/// @brief 		Adds the node ’new’ at the end of the stack.
/// @param lst 	Address of a pointer to the first link of a stack.
/// @param new	Address of a pointer to the node to be added to the stack.
void	ps_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		(ps_stacklast(lst))->next = new;
}

/// @brief 	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’content’ is initialized with
///			the value of the parameter ’content’. The variable
///			’next’ is initialized to NULL.
/// @param value 	The value to create the node with.
/// @return			The new node.
t_stack	*ps_stacknew(int value)
{
	t_stack	*sl1;

	sl1 = NULL;
	sl1 = (t_stack *)malloc(sizeof(t_stack));
	if (!sl1)
		return (NULL);
	sl1->value = value;
	sl1->order = 0;
	sl1->next = NULL;
	return (sl1);
}
