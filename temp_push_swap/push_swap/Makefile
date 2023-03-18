NAME	= push_swap
LIBFT	= libft
SRCS	= main.c \
		argv_check_utils.c \
		argv_check.c \
		error.c \
		get_next_line_utils.c \
		get_next_line.c \
		cmd_ps.c \
		cmd_rrr.c \
		cmd_operation.c \
		sort.c \
		sort_utils.c \
		stack_create.c \
		stack_pop_push.c \
		sort_with35.c

		# sort_quick_merge.c 

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