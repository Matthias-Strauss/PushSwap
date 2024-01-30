# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 21:24:20 by mstrauss          #+#    #+#              #
#    Updated: 2024/01/15 18:28:53 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = ps_atod.c push_swap_utils_rotate.c push_swap_utils_reverse_rotate.c push_swap_utils_swap_push.c push_swap.c main.c push_swap_utils_low_sort.c

OBJECTS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(LIBFT) ${NAME}

debug: CFLAGS += $(DEBUG_FLAGS)
debug: all

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re debug