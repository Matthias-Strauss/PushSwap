# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 18:17:37 by mstrauss          #+#    #+#              #
#    Updated: 2024/02/25 16:10:08 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = atod.c indexing.c main.c parsing_validation.c sorting_utils.c sorting_utils2.c sorting.c stack_double_operations.c stack_operations_wrappers.c stack_operations.c mem_man_malloc.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

DEBUG_FLAGS = -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes

LIBFT_DIR   = ./libft

LIBFT       = $(LIBFT_DIR)/libft.a

all: $(LIBFT) ${NAME}

debug: CFLAGS += $(DEBUG_FLAGS)
debug: 
	make -C $(LIBFT_DIR) debug
	make clean
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFT_DBG):
	make -C $(LIBFT_DIR) debug

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all

tester:
	if [ ! -d "tester" ] || [ ! -f "tester/push_swap_test.sh" ]; then \
		git clone https://github.com/gemartin99/Push-Swap-Tester.git tester; \
	fi
	make all
	mv push_swap tester/
	@read -p "Do you want to run the tester? (y/n) " yn; \
	case "$$yn" in \
		y|Y ) \
			cd tester && ./push_swap_test.sh \
			;; \
	esac

.PHONY: all debug clean fclean re tester