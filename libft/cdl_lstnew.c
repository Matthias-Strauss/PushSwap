/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/24 18:28:26 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’content’ is initialized with
///			the value of the parameter ’content’. The variable
///			’next’ is initialized to NULL.
/// @param content 	The content to create the node with.
/// @return			The new node.
t_node	*cdl_lstnew(int num)
{
	t_node	*sl1;

	sl1 = (t_node *)malloc(sizeof(t_node));
	if (sl1 == NULL)
		return (NULL);
	sl1->num = (int)num;
	sl1->ind = 0;
	sl1->c_rot_up = INT_MAX;
	sl1->c_rot_down = INT_MAX;
	sl1->c_exe = INT_MAX;
	sl1->next = NULL;
	return (sl1);
}
