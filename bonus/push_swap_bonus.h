/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 16:26:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 100000

# include "../libft/libft.h"
# include "../src/push_swap.h"

void	parse_instructions(t_vars *env, char *line, t_node **stk_a,
			t_node **stk_b);

void	rrr(t_node **head_src, t_node **head_dst);
void	rr(t_node **head_src, t_node **head_dst);
void	rb(t_node **head_src);
void	rrb(t_node **head_src);
void	rra(t_node **head_src);
void	ra(t_node **head_src);
void	pa(t_node **stk_src, t_node **stk_dst);
void	pb(t_node **stk_src, t_node **stk_dst);
void	sa(t_node **head_stk);
void	sb(t_node **head_stk);
void	ss(t_node **head_stk_a, t_node **head_stk_b);
#endif