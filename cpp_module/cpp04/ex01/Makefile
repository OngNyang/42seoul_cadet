NAME	=	set_the_world_on_fire
SRCS	=	main.cpp\
			Dog.cpp\
			Cat.cpp\
			Animal.cpp\
			Brain.cpp

OBJS	= $(SRCS:%.cpp=%.o)
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o		:	%.cpp
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re