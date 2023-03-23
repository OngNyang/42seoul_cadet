NAME		= client
NAMESV		= server
LIBFT		= libft
INC			= inc
HEADER		= -I inc
SRC_DIR		= src/
# OBJ_DIR		= obj/
CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
# ECHO		= echo -e

SRCCL_FILES	=	client
SRCSV_FILES	=	server

SRCCL		= 	client.c
OBJCL		= 	$(SRC_DIR)$(SRCCL:%.c=%.o)

SRCSV		= 	server.c
OBJSV		= 	$(SRC_DIR)$(SRCSV:%.c=%.o)

all:		$(NAME) $(NAMESV)

$(NAME):	$(OBJCL)
			make all -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			$(CC) $(FLAGS) $(OBJCL) $(HEADER) libft.a -o $(NAME)

$(NAMESV):	$(OBJSV) $(OBJF)
			$(CC) $(FLAGS) $(OBJSV) $(HEADER) libft.a -o $(NAMESV)

%.o:		 $(SRC_DIR)%.c
			$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean:
			# $(RM) -r $(OBJ_DIR)
			# $(RM) $(OBJF)
			$(RM) $(OBJCL) 
			$(RM) $(OBJSV)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME) $(NAMESV)
			$(RM) $(LIBFT)/libft.a
			$(RM) libft.a
			find . -name ".DS_Store" -delete


re:			fclean start all

norm:
			@clear
			@norminette $(SRC) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		start all clean fclean re bonus norm