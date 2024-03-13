/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:26:09 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 14:50:48 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_node **stk_src, t_node **stk_dst)
{
	push(stk_src, stk_dst);
}

void	pb(t_node **stk_src, t_node **stk_dst)
{
	push(stk_src, stk_dst);
}

void	sa(t_node **head_stk)
{
	swap(head_stk);
}

void	sb(t_node **head_stk)
{
	swap(head_stk);
}
