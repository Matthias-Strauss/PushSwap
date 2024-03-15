/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:26:09 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 15:49:11 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_node **stk_src, t_node **stk_dst)
{
	if (*stk_src == NULL)
		return ;
	push(stk_src, stk_dst);
}

void	pb(t_node **stk_src, t_node **stk_dst)
{
	if (*stk_src == NULL)
		return ;
	push(stk_src, stk_dst);
}

void	sa(t_node **head_stk)
{
	if (*head_stk == NULL)
		return ;
	swap(head_stk);
}

void	sb(t_node **head_stk)
{
	if (*head_stk == NULL)
		return ;
	swap(head_stk);
}
