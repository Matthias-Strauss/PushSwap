/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:06:42 by mstrauss          #+#    #+#             */
/*   Updated: 2024/01/29 19:15:14 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THREE
// 123 132 231 213 321 312

// #FOUR
// 	1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214
//  3241 3412 3421 4123 4132 4213 4231 4312 4321

int	sort2hardcode(char *x)
{
	if (x == 12)
		return (write(1, "\n", 1));
	if (x == 21)
		return (write(1, "sa\n", 3));
}

int	sort3hardcode(char *x)
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

int	sort4hardcode(char *x)
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

int	sort4hardcodecontinued(char *x)
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
