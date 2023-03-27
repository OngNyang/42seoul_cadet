# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:37:42 by hyejeong          #+#    #+#              #
#    Updated: 2022/11/29 23:30:35 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c \
		ft_toupper.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_tolower.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c	\
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
SRCS_B = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
OBJS_B = $(SRCS_B:.c=.o)
CFLAGS = -Wall -Wextra -Wall
CC = cc

ifdef BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(TOTAL_OBJS)
	make all -C ft_printf/
	cp ./ft_printf/libftprintf.a .
	ar -rcs $(NAME) $(TOTAL_OBJS)

bonus:
	make BONUS=1 all
	
all:	$(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.a
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean re bonus
