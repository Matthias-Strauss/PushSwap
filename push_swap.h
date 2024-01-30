/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:37:19 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				order;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **astack);
void				sb(t_stack **bstack);
void				ss(t_stack **astack, t_stack **bstack);
void				pa(t_stack **astack, t_stack **bstack);
void				pb(t_stack **bstack, t_stack **astack);
void				ra(t_stack **astack);
void				rb(t_stack **bstack);
void				rr(t_stack **astack, t_stack **bstack);
void				rra(t_stack **astack);
void				rrb(t_stack **bstack);
void				rrr(t_stack **astack, t_stack **bstack);
int					sort_router(t_stack **astack, t_stack **bstack, int argc);
int					sort2hardcode(t_stack **astack);
int					sort3hardcode(t_stack **astack);
int					sort4hardcode(t_stack **astack, t_stack **bstack, int argc);
int					sort5hardcode(t_stack **astack, t_stack **bstack, int argc);
int					sort_k(t_stack **astack, t_stack **bstack, int argc);
double				ps_atod(const char *str);
void				ps_stackadd_back(t_stack **lst, t_stack *new);
t_stack				*ps_stacklast(t_stack **stack);
t_stack				*ps_stacknew(int value);
int					check_duplicates(t_stack **astack);
int					parse_args(int argc, char *argv[], t_stack **astack);
int					validate_params(t_stack **stack);
#endif