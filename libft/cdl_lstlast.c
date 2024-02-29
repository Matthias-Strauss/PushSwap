/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:13:41 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/10 19:59:51 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Returns the last node of a CIRCULAR DOUBLY LINKED LIST.
/// @param lst 	Beginning of the list.
/// @return 	Last node of the list.
t_node	*cdl_lstlast(t_node **head)
{
	if ((*head)->prev == NULL)
		return (NULL);
	return ((*head)->prev);
}
