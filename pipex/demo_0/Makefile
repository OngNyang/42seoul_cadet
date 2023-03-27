NAME		= pipex
LIBFT		= libft
CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f


OBJS		= 	$(SRCS:%.c=%.o)
SRCS		= 	pipex.c \
				pipex_utils.c \
				main.c

all :		$(NAME)

$(NAME)	: $(OBJS)
		make all -C $(LIBFT)/
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) ./libft/libft.a ./libft/libftprintf.a

%.o		: %.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean	: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re		: fclean all

.PHONY	: all clean fclean re
