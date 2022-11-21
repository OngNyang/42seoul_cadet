# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:37:42 by hyejeong          #+#    #+#              #
#    Updated: 2022/11/21 15:38:49 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isapha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		
OBJS = $(SRCS:.c=.0)
CFLAGS = -Wall -Wextra -Wall

.c.0:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I.

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re