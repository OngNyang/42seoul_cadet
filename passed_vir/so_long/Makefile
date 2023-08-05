# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:49:13 by hyejeong          #+#    #+#              #
#    Updated: 2023/03/06 13:37:34 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

LIBFT		= libft
LIBFT_LIB	= libft.a
MLX_DIR		= -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		= main.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  errors.c \
			  image.c \
			  init.c \
			  map_check.c \
			  map_valid_path.c \
			  map.c \
			  move.c
			  

OBJS 		= $(SRCS:%.c=%.o)

CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make all -C $(LIBFT)/
			$(CC) -o $(NAME) $(OBJS) -Llibft -lft $(MLX_DIR)

%.o			:	%.c
			$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean		:
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean		:	clean
			rm -f $(NAME)
			rm -f $(LIBFT_LIB)
			make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus