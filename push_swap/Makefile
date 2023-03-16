NAME	= push_swap
LIBFT	= libft
SRCS	= main.c \
		argv_check_utils.c \
		argv_check.c \
		commands.c \
		error.c \
		get_next_line_utils.c \
		get_next_line.c \
		operation.c \
		sort.c \
		stack_pop_push.c \
		stack.c

OBJS	= $(SRCS:%.c=%.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

all		: $(NAME)

$(NAME)	: $(OBJS)
		make all -C $(LIBFT)/
		$(CC) -o $(NAME) $(OBJS) -Llibft -lft

%.o		: %.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean	: clean
		rm -f $(NAME)
		rm -f libft.a
		make fclean -C $(LIBFT)

re		: fclean all

.PHONY	: all clean fclean re

#test

debug_make	: $(NAME)
			$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft