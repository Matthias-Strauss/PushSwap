/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:29:54 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 21:09:24 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Handles swapping te top 2 elements if the stack only has 2 elements.
/// @param head Head pointer to the first element in the list.
void	swap_only_2_elem(t_node **head)
{
	t_node	*first;
	t_node	*second;

	first = *head;
	second = first->next;
	first->next = second;
	first->prev = second;
	second->next = first;
	second->prev = first;
	*head = second;
}

/// @brief 	Swaps the two top elements of a Stack built using
///			circular doubly linked list.
/// 		Undefined behavior if list doesnt have 2 elements.
/// @param head Head pointer to the first element in the list.
void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	last = first->prev;
	if (second->next == first && last == first)
		return ;
	if (second->next == first)
		return (swap_only_2_elem(head));
	else
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->next = first;
		second->prev = last;
		last->next = second;
	}
	*head = second;
	return ;
}

/// @brief Pushes from Stack SRC to stack DST.
///        Undefined behavior if stk_src == NULL.
///			undefined behavior if stk_src is only one element.
/// @param stk_src Stack to remove the top element from.
/// @param stk_dst Stack to add the element at the top.
void	push(t_node **stk_src, t_node **stk_dst)
{
	t_node	*src_first;

	src_first = *stk_src;
	*stk_src = (*stk_src)->next;
	if (*stk_src)
	{
		(*stk_src)->prev = src_first->prev;
		src_first->prev->next = *stk_src;
	}
	if (!*stk_dst)
	{
		*stk_dst = src_first;
		src_first->next = src_first;
		src_first->prev = src_first;
	}
	else
	{
		src_first->next = *stk_dst;
		src_first->prev = (*stk_dst)->prev;
		(*stk_dst)->prev->next = src_first;
		(*stk_dst)->prev = src_first;
		*stk_dst = src_first;
	}
}

/// @brief Rotates a Stack.
/// @param head Head Pointer of the Stack to be rotated.
void	rot(t_node **head)
{
	if (*head != NULL)
		*head = (*head)->next;
}

/// @brief Reverse Rotates a Stack.
/// @param head Head Pointer of the Stack to be reverse rotated.
void	rev_rot(t_node **head)
{
	if (*head != NULL)
		*head = (*head)->prev;
}
