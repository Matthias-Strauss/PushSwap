/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:45:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/10 22:06:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst)
{
	int	rr;

	if (node_src->c_rot_up < node_dst->c_rot_up)
		rr = node_src->c_rot_up;
	else
		rr = node_dst->c_rot_up;
	exec->dbl_rot = rr;
}

void	calc_rev_dbl_rot(t_exec *exec, t_node *node_src, t_node *node_dst)
{
	int	rrr;

	if (node_src->c_rot_down < node_dst->c_rot_down)
		rrr = node_src->c_rot_down;
	else
		rrr = node_dst->c_rot_down;
	exec->dbl_rrot = rrr;
}

void	calc_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst)
{
	if (node_src->c_rot_up <= exec->dbl_rot)
		exec->rot_src = 0;
	else
		exec->rot_src = node_src->c_rot_up - exec->dbl_rot;
	if (node_dst->c_rot_up <= exec->dbl_rot)
		exec->rot_dst = 0;
	else
		exec->rot_dst = node_dst->c_rot_up - exec->dbl_rot;
}

void	calc_rev_rot_rest(t_exec *exec, t_node *node_src, t_node *node_dst)
{
	if (node_src->c_rot_down <= exec->dbl_rrot)
		exec->rot_src = 0;
	else
		exec->rot_src = node_src->c_rot_down - exec->dbl_rrot;
	if (node_dst->c_rot_down <= exec->dbl_rrot)
		exec->rot_dst = 0;
	else
		exec->rot_dst = node_dst->c_rot_down - exec->dbl_rrot;
}

void	reset_all(t_vars *env)
{
	reset_c_vars(env->a);
	cheapest_rotate_to_top(env->a);
	if (env->b != NULL)
	{
		reset_c_vars(env->b);
		cheapest_rotate_to_top(env->b);
	}
}
