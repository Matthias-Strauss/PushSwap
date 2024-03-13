/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:20:33 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/12 12:13:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef NULL
// # define NULL ((void *)0)
// #endif

#ifndef LIBFT_H
# define LIBFT_H
# define STD_ERR 2
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// ############################################################	//
//		TypeDef -- Circular Doubly Linked List 					//
// ############################################################ //
// COMBINATION:
// 0 = undefined, 1 = both up, 2 = both down,
// 3 = src up dst down, 4 = src down & dst up
typedef struct s_node
{
	int				num;
	int				ind;
	int				c_rot_up;
	int				c_rot_down;
	int				c_exe;
	int				combination;
	struct s_node	*best_pair;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// ############################################################ //
//		Functions -- Circular Doubly Linked List 				//
// ############################################################ //
void				cdl_lstadd_back(t_node **lst, t_node *new);
void				cdl_lstadd_front(t_node **lst, t_node *new);
void				cdl_lstclear(t_node **lst);
void				cdl_lstdelone(t_node *lst, void (*del)(void *));
void				cdl_lstiter(t_node **head, void (*f)(void *));
t_node				*cdl_lstlast(t_node **head);
t_node				*cdl_lstmap(t_node *lst, void *(*f)(void *),
						void (*del)(void *));
t_node				*cdl_lstnew(int num);
int					cdl_lstlen(t_node *stack);
int					cdl_lstsize(t_node **head);

// ############################################################	//
//		TypeDef -- Allocated Memory Linked List 				//
// ############################################################ //
typedef struct s_mem
{
	void			*mem;
	struct s_mem	*next;
}					t_mem;

// ############################################################ //
//		Functions -- Memory Management 							//
// ############################################################ //
// void				*mem_man_malloc(t_vars *env, size_t size);
void				mem_lstadd_front(t_mem **head, t_mem *new);
void				mem_lstclear(t_mem **lst, void (*del)(void *));
t_mem				*mem_lstnew(void *mem);
void				mem_lstdelone(t_mem *lst, void (*del)(void *));

// ############################################################ //
//		Functions -- General Functions							//
// ############################################################ //
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
#endif