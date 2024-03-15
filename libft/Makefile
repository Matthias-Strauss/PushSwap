# NAME, all, clean, fclean, re
# -Wall -Wextra -Werror
# You must use the command ar to create your library. Using the libtool command is forbidden.
# Your libft.a has to be created at the root of your repository.
# If you need helper functions to split a more complex function, define them as static
# functions. This way, their scope will be limited to the appropriate file.

NAME = libft.a

BUILD_DIR = ../build

SRCS = 	cdl_lstadd_back.c\
cdl_lstadd_front.c\
cdl_lstclear.c\
cdl_lstdelone.c\
cdl_lstiter.c\
cdl_lstlast.c\
cdl_lstlen.c\
cdl_lstmap.c\
cdl_lstnew.c\
cdl_lstsize.c\
mem_lstadd_front.c\
mem_lstclear.c\
mem_lstnew.c\
mem_lstdelone.c\
ft_putstr_fd.c\
ft_putnbr_fd.c\
ft_putchar_fd.c\
ft_strncmp.c\
ft_bzero.c\
get_next_line.c\
get_next_line_utils.c\
get_next_line_utils_bonus.c\
get_next_line_bonus.c\

OBJECTS = $(SRCS:.c=.o)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS))

BONUS_OBJS = $(BONUS:.c=.o)
BONUS_OBJS := $(addprefix $(BUILD_DIR)/, $(BONUS_OBJS))

CC = gcc

CFLAGS = -Wall -Werror -Wextra
VALGRIND_FLAGS = -g
DEBUG_FLAGS = -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(OBJECTS)
	ar -rcs $(BUILD_DIR)/$(NAME) $(OBJECTS)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(BUILD_DIR)/$(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar -rcs $(BUILD_DIR)/$(NAME) $(OBJECTS) $(BONUS_OBJS)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BUILD_DIR)/$(NAME)

valgrind: CFLAGS += $(VALGRIND_FLAGS)
valgrind: $(BUILD_DIR)/$(NAME)

.PHONY: clean fclean all re ar bonus debug valgrind