/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:43:07 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 14:46:25 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// LIBFT FUNCTIONS:
// ft_getnextline()
// ft_strncmp()
// ft_split()

void	parse_instructions(char *line, t_node **stk_a, t_node **stk_b)
{
	if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stk_a, stk_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stk_a, stk_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stk_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stk_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stk_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stk_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stk_b, stk_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stk_a, stk_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stk_a, stk_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stk_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stk_b);
}

//  int	check_is_sorted(t_node **head, int arg_count)
// {
// 	t_node	*cur_node;
// 	int		i;

// 	if (*head == NULL)
// 		exit(write(1, "Error\n", 6));
// 	cur_node = (*head)->next;
// 	i = 1;
// 	while (cur_node != *head)
// 	{
// 		if (cur_node->ind >= cur_node->next->ind)
// 			return (0);
// 		cur_node = cur_node->next;
// 		i++;
// 	}
// 	if (i != arg_count)
// 		return (0);
// 	return (1);
// }

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
		return (1);
	is_char_digit_or_sign(argc, argv);
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
		return (ft_putstr_fd("OK\n", 1), 1);
	else
		return (ft_putstr_fd("KO\n", 1), 0);
	free_all(environment);
}
