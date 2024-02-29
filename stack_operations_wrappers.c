/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_wrappers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:04:19 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 21:09:23 by mstrauss         ###   ########.fr       */
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

void	w_ra(t_node **head_src)
{
	rot(head_src);
	ft_putstr_fd("ra\n", 1);
}

void	w_rra(t_node **head_src)
{
	rev_rot(head_src);
	ft_putstr_fd("rra\n", 1);
}

void	w_rrb(t_node **head_src)
{
	rev_rot(head_src);
	ft_putstr_fd("rrb\n", 1);
}

void	w_rb(t_node **head_src)
{
	rot(head_src);
	ft_putstr_fd("rb\n", 1);
}

void	w_rr(t_node **head_src, t_node **head_dst)
{
	rr(head_src, head_dst);
	ft_putstr_fd("rr\n", 1);
}

void	w_rrr(t_node **head_src, t_node **head_dst)
{
	rrr(head_src, head_dst);
	ft_putstr_fd("rrr\n", 1);
}
