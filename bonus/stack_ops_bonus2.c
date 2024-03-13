/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:27:07 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 14:50:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_node **head_src)
{
	rot(head_src);
}

void	rra(t_node **head_src)
{
	rev_rot(head_src);
}

void	rrb(t_node **head_src)
{
	rev_rot(head_src);
}

void	rb(t_node **head_src)
{
	rot(head_src);
}
