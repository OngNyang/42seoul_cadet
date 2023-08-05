# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:29:13 by hyejeong          #+#    #+#              #
#    Updated: 2023/03/29 13:29:29 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFT		= libft
CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f


OBJS		= 	$(SRCS:%.c=%.o)
SRCS		= 	pipex.c \
				pipex_utils.c \
				pipex_utils2.c \
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
