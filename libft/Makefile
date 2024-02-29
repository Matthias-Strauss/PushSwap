# NAME, all, clean, fclean, re
# -Wall -Wextra -Werror
# You must use the command ar to create your library. Using the libtool command is forbidden.
# Your libft.a has to be created at the root of your repository.
# If you need helper functions to split a more complex function, define them as static
# functions. This way, their scope will be limited to the appropriate file.

NAME = libft.a

SRCS = 	cdl_lstadd_back.c cdl_lstadd_front.c cdl_lstclear.c cdl_lstdelone.c cdl_lstiter.c cdl_lstlast.c cdl_lstlen.c cdl_lstmap.c cdl_lstnew.c cdl_lstsize.c\
        mem_lstadd_front.c mem_lstclear.c mem_lstnew.c mem_lstdelone.c\
        ft_putstr_fd.c

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

DEBUG_FLAGS = -g

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(NAME)

.PHONY: clean fclean all re ar bonus debug