# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 18:17:37 by mstrauss          #+#    #+#              #
#    Updated: 2024/03/15 13:33:51 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_DIR = ./src
BONUS_DIR = ./bonus
BUILD_DIR = ./build

SRCS =$(addprefix $(SRC_DIR)/,  atod.c\
indexing.c\
init_and_free.c\
executooor.c\
executooor_a_to_b.c\
executooor_b_to_a.c\
main.c\
mem_man_malloc.c\
parsing_validation.c\
sort_big.c\
sorting.c\
sorting_utils.c\
sorting_utils2.c\
stack_operations.c\
stack_operations2.c\
stack_double_operations.c\
stack_operations_wrappers.c\
stack_operations_wrappers2.c\
stack_operations_wrappers3.c\
)

BONUS_SRCS= $(addprefix $(SRC_DIR)/, atod.c\
indexing.c\
init_and_free.c\
mem_man_malloc.c\
parsing_validation.c\
sorting_utils.c\
sorting_utils2.c\
stack_operations.c\
stack_operations2.c\
stack_double_operations.c\
)\
$(addprefix $(BONUS_DIR)/, stack_ops_bonus.c\
stack_ops_bonus2.c\
executooor_a_to_b_bonus.c\
executooor_b_to_a_bonus.c\
main_bonus.c\
sort_check_bonus.c\
executooor_bonus.c\
)

OBJECTS = $(SRCS:.c=.o)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(notdir $(OBJECTS)))

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)
BONUS_OBJECTS := $(addprefix $(BUILD_DIR)/, $(notdir $(BONUS_OBJECTS)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

DEBUG_FLAGS = -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes

VALGRIND_FLAGS = -g

LIBFT_DIR   = ./libft
LIBFT       = $(BUILD_DIR)/libft.a


all: $(LIBFT) ${NAME}

debug: CFLAGS += $(DEBUG_FLAGS)
debug: 
	make -C $(LIBFT_DIR) debug
	make clean
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

valgrind: CFLAGS += $(VALGRIND_FLAGS)
valgrind:
	make -C $(LIBFT_DIR) valgrind
	make clean
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

bonus: CFLAGS += $(DEBUG_FLAGS)
bonus: $(LIBFT) $(BONUS_OBJECTS)
	${CC} ${CFLAGS} -o checker ${BONUS_OBJECTS} $(LIBFT)

${NAME}: ${OBJECTS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFT_DBG):
	make -C $(LIBFT_DIR) debug

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}
	rm -f ${BONUS_OBJECTS}

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}
	rm -f checker

re: fclean all

tester:
	if [ ! -d "tester" ] || [ ! -f "tester/push_swap_test.sh" ]; then \
		git clone https://github.com/gemartin99/Push-Swap-Tester.git tester; \
	fi
	make fclean
	make all
	make clean
	make bonus
	make clean
	mv push_swap tester/
	mv checker tester/
	@read -p "Do you want to run the tester? (y/n) " yn; \
	case "$$yn" in \
		y|Y ) \
			cd tester && chmod +x ./push_swap_test.sh && ./push_swap_test.sh \
			;; \
	esac

rmtester:
	rm -rf tester/

.PHONY: all debug clean fclean re tester rmtester