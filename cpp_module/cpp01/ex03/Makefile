NAME	=	unnecessary_violence
SRCS	=	main.cpp\
			Weapon.cpp\
			HumanA.cpp\
			HumanB.cpp

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