/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:34:40 by mstrauss          #+#    #+#             */
/*   Updated: 2024/02/27 16:54:51 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

// is_char_digit()	protects against wrong char parameters
// atod()			protects against numbers outside of INT range

/// @brief Initializes the Environment Struct holding essential variables.
/// @param environment The Struct to initialize.
/// @param argc The ARGC from main().
/// @param argv The ARGV from main().
/// @return Pointer to the struct.
void	initialize_vars(t_vars *environment, int argc, char *argv[])
{
	int		i;
	t_node	*tmp;

	environment->reverse = 0;
	environment->argv = argv;
	environment->argc = argc;
	environment->a = NULL;
	environment->b = NULL;
	environment->mem_lst_head = NULL;
	i = argc - 1;
	environment->a = cdl_lstnew(atod(argv[i--]));
	if (!environment->a)
		exit(1);
	environment->a->next = environment->a;
	environment->a->prev = environment->a;
	while (i > 0)
	{
		tmp = cdl_lstnew(atod(argv[i]));
		if (!tmp)
			exit(1);
		cdl_lstadd_front(&environment->a, tmp);
		i--;
	}
}

/// @brief 	Push_Swap aims to take in a variable amount of parameters
/// 		(range: INT) and sort them using the least amount of
/// 		Stack Operations as possible.
/// @param argc The amount of arguments + 1 (program name).
/// @param argv The numbers to be sorted, as Strings.
/// @return	Outputs the operations needed to sort the list to STD_OUT.
int	main(int argc, char *argv[])
{
	t_vars	*environment;

	if (argc < 2)
		return (0);
	environment = malloc(sizeof(t_vars));
	if (environment == NULL)
		return (0);
	is_char_digit_or_sign(argc, argv);
	initialize_vars(environment, argc, argv);
	check_duplicate(&environment->a);
	indexing(&environment->a, argc - 1);
	sorting_router(environment);
	while (cdl_lstlen(environment->a) > 3)
	{
		reset_all(environment);
		sort_big(environment);
	}
	sort3(&environment->a);
	environment->reverse = 1;
	while (check_is_sorted(&environment->a, environment->argc - 1))
	{
		reset_all(environment);
		sort_big(environment);
	}
	// free_all();
}
