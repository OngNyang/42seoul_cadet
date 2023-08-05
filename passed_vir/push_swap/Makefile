# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 20:53:57 by hyejeong          #+#    #+#              #
#    Updated: 2023/03/20 13:39:24 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= libft
SRCS	= main.c \
		argv_check_utils.c \
		argv_check.c \
		cmd_operation.c \
		cmd_ps.c \
		cmd_rrr.c \
		error.c \
		get_next_line_utils.c \
		get_next_line.c \
		sort_divide_merge.c \
		sort_utils.c \
		sort_utils2.c \
		sort.c \
		stack_create.c \
		stack_pop_push.c

OBJS	= $(SRCS:%.c=%.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

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