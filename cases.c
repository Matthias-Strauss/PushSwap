/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:06:42 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/02 13:03:25 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort2hardcode(int x)
{
	if (x == 12)
		return (write(1, "\n", 1));
	if (x == 21)
		return (write(1, "sa\n", 3));
}

int	sort3hardcode(int x)
{
	if (x == 123)
		return (write(1, "\n", 1));
	if (x == 132)
		return (write(1, "sa\nra\n", 6));
	if (x == 231)
		return (write(1, "rra\n", 4));
	if (x == 213)
		return (write(1, "sa\n", 1));
	if (x == 321)
		return (write(1, "sa\nrra\n", 6));
	if (x == 312)
		return (write(1, "ra\n", 3));
}

int	sort4hardcode(int x)
{
	if (x == 1234)
		return (write(1, "\n", 1));
	if (x == 1243)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	if (x == 1324)
		return (write(1, "ra\nsa\nrra\nsa\n", 14));
	if (x == 1342)
		return (write(1, "ra\nsa\nrra\n", 11));
	if (x == 1423)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	if (x == 1432)
		return (write(1, "sa\nra\nsa\nrra\n", 14));
	if (x == 2134)
		return (write(1, "sa\n", 3));
	if (x == 2143)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	if (x == 2314)
		return (write(1, "ra\nsa\nrra\n", 11));
	if (x == 2341)
		return (write(1, "ra\nsa\nrra\nsa\n", 14));
	if (x == 2413)
		return (write(1, "sa\nra\nsa\nrra\n", 14));
	if (x == 2431)
		return (write(1, "sa\n", 3));
	return (sort4hardcodecontinued(x));
}

int	sort4hardcodecontinued(int x)
{
	if (x == 3124)
		return (write(1, "ra\nsa\nrra\nsa\n", 14));
	if (x == 3142)
		return (write(1, "ra\nsa\nrra\n", 11));
	if (x == 3214)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	if (x == 3241)
		return (write(1, "sa\nra\nsa\nrra\n", 14));
	if (x == 3412)
		return (write(1, "ra\nsa\nrra\nsa\n", 14));
	if (x == 3421)
		return (write(1, "ra\nsa\nrra\n", 11));
	if (x == 4123)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	if (x == 4132)
		return (write(1, "sa\nra\nsa\nrra\n", 14));
	if (x == 4213)
		return (write(1, "ra\nsa\nrra\nsa\n", 14));
	if (x == 4231)
		return (write(1, "ra\nsa\nrra\n", 11));
	if (x == 4312)
		return (write(1, "sa\nra\nsa\nrra\nsa\n", 18));
	return (write(1, "sa\nra\nsa\nrra\n", 14));
}

void	sort5hardcode(t_stack **astack, t_stack **bstack, int argc)
{
	t_stack	*tmp;

	tmp = *astack;
	while (tmp != NULL)
	{
		if (tmp->order == 1)
		{
			pb(bstack, astack);
			return (sort4hardcode(low_param_checksum(astack, argc - 1)),
				write(1, "pa\n", 3));
		}
		tmp = tmp->next;
	}
}
