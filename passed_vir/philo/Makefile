# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 12:45:04 by hyejeong          #+#    #+#              #
#    Updated: 2023/05/24 18:18:05 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	atoi.c\
			error.c\
			ft_strlen.c\
			init1.c\
			init2.c\
			main.c\
			monitor.c\
			terminate.c\
			thread1.c\
			thread2.c\
			utils.c

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