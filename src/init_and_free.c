/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:21:16 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 12:21:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Initializes the Environment Struct holding essential variables.
/// @param environment The Struct to initialize.
/// @param argc The ARGC from main().
/// @param argv The ARGV from main().
/// @return Pointer to the struct.
void	initialize_vars(t_vars *environment, int argc, char *argv[])
{
	t_node	*tmp;

	environment->reverse = 0;
	environment->argv = argv;
	environment->argc = argc;
	environment->a = NULL;
	environment->b = NULL;
	environment->a = cdl_lstnew(atod(argv[--argc]));
	if (!environment->a)
		exit(1);
	environment->a->next = environment->a;
	environment->a->prev = environment->a;
	while (argc > 1)
	{
		tmp = cdl_lstnew(atod(argv[--argc]));
		if (!tmp)
			exit(1);
		cdl_lstadd_front(&environment->a, tmp);
	}
}

void	free_all(t_vars *env)
{
	cdl_lstclear(&env->a);
	free(env);
}
