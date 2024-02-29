/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/12 13:48:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’content’ is initialized with
///			the value of the parameter ’content’. The variable
///			’next’ is initialized to NULL.
/// @param mem 	The content to create the node with.
/// @return		The new node.
t_mem	*mem_lstnew(void *mem)
{
	t_mem	*sl1;

	sl1 = (t_mem *)malloc(sizeof(t_mem));
	if (sl1 == NULL)
		return (0);
	sl1->mem = mem;
	sl1->next = NULL;
	return (sl1);
}
