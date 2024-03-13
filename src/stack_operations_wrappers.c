/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_wrappers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:04:19 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 21:48:27 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	w_pa(t_node **stk_src, t_node **stk_dst)
{
	push(stk_src, stk_dst);
	ft_putstr_fd("pa\n", 1);
}

void	w_pb(t_node **stk_src, t_node **stk_dst)
{
	push(stk_src, stk_dst);
	ft_putstr_fd("pb\n", 1);
}

void	w_sa(t_node **head_stk)
{
	swap(head_stk);
	ft_putstr_fd("sa\n", 1);
}

void	w_sb(t_node **head_stk)
{
	swap(head_stk);
	ft_putstr_fd("sb\n", 1);
}

void	w_ss(t_node **head_stk_a, t_node **head_stk_b)
{
	swap(head_stk_a);
	swap(head_stk_b);
	ft_putstr_fd("ss\n", 1);
}
