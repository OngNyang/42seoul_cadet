# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 16:02:56 by hyejeong          #+#    #+#              #
#    Updated: 2022/12/09 16:02:59 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_base_fd.c \
		ft_printf.c \
		ft_putunbr_fd.c \
		ft_putp.c \
		ft_puthexnbr.c

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