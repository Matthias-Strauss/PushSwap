/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_wrappers2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:48:13 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 21:49:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
