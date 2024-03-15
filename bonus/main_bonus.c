/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:43:07 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/15 14:08:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// LIBFT FUNCTIONS:
// ft_getnextline()
// ft_strncmp()
// ft_split()

void	parse_instructions(char *line, t_node **stk_a, t_node **stk_b)
{
	if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(stk_a, stk_b);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rra(stk_a);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rrb(stk_b);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(stk_a, stk_b);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra(stk_a);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rb(stk_b);
	else if (ft_strncmp(line, "pa", 2) == 0)
		pa(stk_b, stk_a);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(stk_a, stk_b);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(stk_a, stk_b);
	else if (ft_strncmp(line, "sa", 2) == 0)
		sa(stk_a);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sb(stk_b);
	ft_bzero(line, 6);
}

/// @brief Takes an unsorted list of integers as parameters. Then listens to
/// STDIN for stack operation instructions in order to sort the list using
/// two stacks.
/// @param argc Amount of arguments provided.
/// @param argv Store of arguments as char*.
/// @return "OK\n" on STDOUT when successfully sorted.
/// 		"KO\n" on STDOUT when successfully sorted.
int	main(int argc, char **argv)
{
	int		bytesread;
	char	*commands;
	t_vars	*environment;

	environment = malloc(sizeof(t_vars));
	if (environment == NULL || argc < 2)
		return (1);
	commands = malloc(sizeof(char) * BUFFER_SIZE);
	if (!commands)
		return (free(environment), 1);
	// is_char_digit_or_sign(environment, argc, argv);
	initialize_vars(environment, argc, argv);
	check_duplicate(&environment->a);
	indexing(&environment->a, argc - 1);
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(0, commands, BUFFER_SIZE);
		parse_instructions(commands, &environment->a, &environment->b);
	}
	if (check_is_sorted(&environment->a, argc - 1) && environment->b == NULL)
		return (free_all(environment), ft_putstr_fd("OK\n", 1), 1);
	else
		return (free_all(environment), ft_putstr_fd("KO\n", 1), 0);
}
