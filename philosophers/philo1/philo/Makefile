NAME	= philo
SRCS	= main.c

OBJS	= $(SRCS:%.c=%.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o		:	%.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re