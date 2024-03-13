/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:00:31 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/23 21:09:31 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Converts a number from string to double, ignores leading whitespace.
///			Protects against input out of range of MAX_INT & MIN_INT.
/// @param str String to convert.
/// @return Number as an double.
int	atod(const char *str)
{
	size_t	i;
	double	sign;
	double	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (is_char_digit(str[i]))
		sum = (str[i++] - '0') + (sum * 10);
	if (sum > INT_MAX || sum < INT_MIN)
	{
		write(STD_ERR, "Error\n", 6);
		exit(1);
	}
	return ((int)(sign * sum));
}
