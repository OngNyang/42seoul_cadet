NAME	=	minitalk.a
CLIENT	=	client
SERVER	=	server

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

FTPRINTF		=	./ft_printf.a
FTPRINTF_DIR	=	./ft_printf

SRC_C	=	client.c
SRC_S	=	server.c
INC		=	-I. -I$(LIBFT_DIR) -I$(FTPRINTF_DIR)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

all:	$(SERVER) $(CLIENT)

$(NAME):	all

$(SERVER) : $(LIBFT)
		$(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)

$(CLIENT) : $(LIBFT)
		$(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

$(FTPRINTF):
		$(MAKE) -C ./ft_printf

clean:
		$(RM) $(CLIENT) $(SERVER)
fclean:
		$(MAKE) fclean -C $(LIBFT_DIR) -C $(FTPRINTF_DIR)
		$(RM) $(CLIENT) $(SERVER)

re : fclean all

.PHONY: all clean fclean re
