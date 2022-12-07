NAME = libftprintf.a

SRCS = 

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