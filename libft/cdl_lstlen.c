/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_lstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:24:36 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/21 20:28:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cdl_lstlen(t_node *stack)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (stack == NULL)
		return (0);
	if (stack->next == stack)
		return (1);
	tmp = stack->next;
	while (tmp != stack)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
