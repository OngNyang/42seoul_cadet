NAME = get_next_line.a

SRCS = get_next_line_utils.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Wall
CC = cc

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