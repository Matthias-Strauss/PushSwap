/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:32:40 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 16:10:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	SIZE_OF()
//	t_vars:	40
//	t_mem:	16
//	t_node:	48

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

// ############################################################	//
//						Execute Struct 							//
// ############################################################ //
typedef struct s_exec
{
	int		dbl_rot;
	int		dbl_rrot;
	int		rot_src;
	int		rot_dst;
	int		rrot_src;
	int		rrot_dst;
	int		combination;
	t_node	*best_src;
	t_node	*best_dst;
}			t_exec;

// ############################################################	//
//						Environment Struct 						//
// ############################################################ //
typedef struct s_vars
{
	int		argc;
	int		reverse;
	char	**argv;
	t_node	*a;
	t_node	*b;
	t_mem	*mem_lst_head;
}			t_vars;

// ############################################################	//
//					Sorting Functions							//
// ############################################################ //
void		reset_c_vars(t_node *stk);
void		cheapest_rotate_to_top(t_node *head);
void		calc_c_exec(t_node *stk_src, t_node *stk_dst, t_node *best_src,
				t_node *best_dst);
int			node3calc(t_node *src, t_node *high_ind, t_node *best_dst);
void		calc_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
void		calc_rev_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst);
void		calc_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
void		calc_rev_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst);
void		reset_all(t_vars *env);
int			check_is_sorted(t_node **head, int arg_count);
void		sorting_router(t_vars *env);
void		sort2(t_node **head);
void		sort3(t_node **head);
void		sort4(t_vars *env);
void		sort_big(t_vars *env);
void		sort_loop(t_vars *env);

// ############################################################	//
//			Building Stack Operation Execution Chain			//
// ############################################################ //
void		execute(t_exec *exec, t_node **head_src, t_node **head_dst);
t_node		*init_cheapest_exec(t_node *head_src, t_node *head_dst);
void		calc_node_c_exec(t_node *src, t_node *dst);
void		executor_router(t_node *c_node, t_vars *env);
void		calc_node_c_exec_continued(t_node *src, t_node *dst);
void		executooor_a_to_b_up(t_node *c_node, t_vars *env);
void		executooor_a_to_b_down(t_node *c_node, t_vars *env);
void		executooor_a_to_b_updown(t_node *c_node, t_vars *env);
void		executooor_a_to_b_downup(t_node *c_node, t_vars *env);
void		executooor_b_to_a_up(t_node *c_node, t_vars *env);
void		executooor_b_to_a_down(t_node *c_node, t_vars *env);
void		executooor_b_to_a_downup(t_node *c_node, t_vars *env);
void		executooor_b_to_a_updown(t_node *c_node, t_vars *env);

// ############################################################	//
//						Utility									//
// ############################################################ //
int			atod(const char *str);
void		*mem_man_malloc(t_vars *env, size_t size);
t_node		*higher_ind_in_stk(int ind, t_node *head);
t_node		*lower_ind_in_stk(int ind, t_node *head);
void		indexing(t_node **head, int count);
// int			max_ind_stack(t_node *head);
// int			min_ind_stack(t_node *head);
void		initialize_vars(t_vars *environment, int argc, char *argv[]);
void		free_all(t_vars *env);
void		error(t_vars *env);

// ############################################################	//
//				Parsing and Validation							//
// ############################################################ //
int			is_space(int c);
void		is_char_digit_or_sign(t_vars *env, int argc, char *argv[], int i);
int			is_char_digit(int c);
void		check_duplicate(t_node **head);

// ############################################################	//
//						Stack Operators							//
// ############################################################ //
void		rot_to_min(t_node **head);
void		swap_only_2_elem(t_node **head);
void		swap(t_node **head);
void		push(t_node **stk_src, t_node **stk_dst);
void		push_last_node(t_node **stk_src, t_node **stk_dst);
void		rot(t_node **head);
void		rev_rot(t_node **head);
void		ss(t_node **a_head, t_node **b_head);
void		rr(t_node **a_head, t_node **b_head);
void		rrr(t_node **a_head, t_node **b_head);

// ############################################################	//
//			Wrapped Stack Operators w/ OUTPUT					//
// ############################################################ //
void		w_pa(t_node **stk_src, t_node **stk_dst);
void		w_pb(t_node **stk_src, t_node **stk_dst);
void		w_sa(t_node **head_stk);
void		w_sb(t_node **head_stk);
void		w_ss(t_node **head_stk_a, t_node **head_stk_b);
void		w_ra(t_node **head_src);
void		w_rra(t_node **head_src);
void		w_rrb(t_node **head_src);
void		w_rb(t_node **head_src);
void		w_rr(t_node **head_src, t_node **head_dst);
void		w_rrr(t_node **head_src, t_node **head_dst);
#endif