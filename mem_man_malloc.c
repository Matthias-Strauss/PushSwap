/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_man_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:18:45 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 15:36:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

/// @brief Wrapper for malloc, adding a pointer to the allocated memory
/// 		in order to be able to free it later.
/// @param env 	Environment struct containing the allocated_mem_list
/// @param size Amount of bytes to allocate
/// @return 	Void
void	*mem_man_malloc(t_vars *env, size_t size)
{
	void	*tmp;
	t_mem	*new_node;

	if (env == NULL || env->mem_lst_head == NULL)
		// need to initialize first somewhere else, or implement init here
		return (NULL);
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	new_node = mem_lstnew(tmp);
	if (!new_node)
		return (free(tmp), NULL);
	mem_lstadd_front(env->mem_lst_head, tmp);
	return (tmp);
}
