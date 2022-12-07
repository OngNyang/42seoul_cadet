NAME = libftprintf.a

SRCS = ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_base_fd.c \
		ft_printf.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Wall
CC = cc

# ifdef BONUS
# 	TOTAL_OBJS = $(OBJS) $(OBJS_B)
# else
# 	TOTAL_OBJS = $(OBJS)
# endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re bonus