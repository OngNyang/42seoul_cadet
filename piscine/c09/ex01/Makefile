# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:19:02 by hyejeong          #+#    #+#              #
#    Updated: 2022/10/20 15:28:00 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_swap.c \
srcs/ft_strlen.o
NAME = libft.a
OBJ = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o} -I ./includes/

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}
	
clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all