/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:42:35 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 21:04:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strlen(const char *s);
int		gnl_strchr(char *s, int c);
void	gnl_bzero(void *s, size_t n);

#endif
