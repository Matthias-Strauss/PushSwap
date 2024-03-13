/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:27 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/11 19:12:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Checks if a character is an ASCII whitespace character
/// @param c character to check
/// @return 1 if c is a whitespace, 0 if c isn't a whitespace
int	is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

/// @brief Checks if all the Strings stored in argv are digits.
/// @param argc Amount of arguments that need to be checked (-1).
/// @param argv Array of arguments in the form of Strings.
/// @return 0 if no illegal characters were found.
/// 		Exit program if illegals found.
int	is_char_digit_or_sign(int argc, char *argv[])
{
	int		i;
	int		signs;
	char	*tmp;

	i = 1;
	signs = 0;
	while (i < argc)
	{
		tmp = argv[i];
		while (*tmp != '\0')
		{
			if (*tmp == '+' || *tmp == '-')
				signs += 1;
			if ((!(*tmp >= '0' && *tmp <= '9') && !(*tmp == '+')
					&& !(*tmp == '-')) || signs >= 1)
			{
				write(STD_ERR, "Error\n", 6);
				exit(1);
			}
			tmp++;
		}
		signs = 0;
		i++;
	}
	return (0);
}

/// @brief Returns TRUE if character is between 0 and 9.
/// @param c Character to be tested.
/// @return TRUE if digit, FALSE if not.
int	is_char_digit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

/// @brief Checks the parameters of the stack for duplicates.
/// @param stack Stack to be checked.
/// @return	Amount of errors found.
void	check_duplicate(t_node **head)
{
	t_node	*current;
	t_node	*rest;

	current = *head;
	while (current != NULL)
	{
		rest = current->next;
		while (rest != NULL)
		{
			if (current->num == rest->num)
			{
				write(STD_ERR, "Error\n", 6);
				exit(1);
			}
			if (rest->next == *head)
				break ;
			rest = rest->next;
		}
		current = current->next;
		if (current->next == *head)
			break ;
	}
	return ;
}
