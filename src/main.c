/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:34:40 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/13 10:56:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

/// @brief 	Push_Swap aims to take in a variable amount of parameters
/// 		(range: INT) and sort them using the least amount of
/// 		Stack Operations as possible.
/// @param argc The amount of arguments + 1 (program name).
/// @param argv The numbers to be sorted, as Strings.
/// @return	Outputs the operations needed to sort the list to STD_OUT.
int	main(int argc, char *argv[])
{
	t_vars	*environment;

	environment = malloc(sizeof(t_vars));
	if (environment == NULL || argc < 2)
		return (1);
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
	while (environment->b != NULL)
	{
		reset_all(environment);
		sort_big(environment);
	}
	rot_to_min(&environment->a);
	free_all(environment);
}
