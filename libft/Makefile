# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:37:42 by hyejeong          #+#    #+#              #
#    Updated: 2022/11/25 15:09:43 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS	= -Wall -Wextra -Wall

SRCS_1	= ft_strlen.c		\
		  ft_strlcpy.c		\
		  ft_strlcat.c		\
		  ft_strchr.c		\
		  ft_strnstr.c		\
		  ft_strncmp.c		\
		  ft_strdup.c		\
		  ft_strrchr.c		\
		  ft_memset.c		\
		  ft_memcpy.c		\
		  ft_memmove.c		\
		  ft_memchr.c		\
		  ft_memcmp.c		\
		  ft_bzero.c		\
		  ft_atoi.c		\
		  ft_calloc.c		\
		  ft_isalnum.c		\
		  ft_isalpha.c		\
		  ft_isascii.c		\
		  ft_isdigit.c		\
		  ft_isprint.c		\
		  ft_strdup.c		\
		  ft_tolower.c		\
		  ft_toupper.c		\
			
SRCS_2	= ft_substr.c		\
		  ft_strjoin.c		\
		  ft_strtrim.c		\
		  ft_split.c		\
		  ft_strmapi.c		\
		  ft_itoa.c		\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl_fd.c	\
		  ft_putnbr_fd.c	\
		  ft_striteri.c

SRCS_BNS = ft_lstnew.c		\
		  ft_lstsize.c		\
		  ft_lstadd_front.c	\
		  ft_lstadd_back.c	\
		  ft_lstclear.c	\
		  ft_lstlast.c		\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_lstdelone.c	\

SRCS	= $(SRCS_1)	\
		  $(SRCS_2)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BNS:.c=.o)

all:	$(NAME)

%.o:	%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $^

.PHONY: all clean fclean re
