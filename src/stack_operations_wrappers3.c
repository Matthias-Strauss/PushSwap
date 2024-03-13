/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_wrappers3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:48:54 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 21:49:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	w_rrr(t_node **head_src, t_node **head_dst)
{
	rrr(head_src, head_dst);
	ft_putstr_fd("rrr\n", 1);
}
