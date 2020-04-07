##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Thomas Olry's Makefile made the 12/30/2019
##

SRC	=	srcs/main.c			\
		srcs/ia.c			\
		srcs/ia2.c			\
		srcs/game.c			\
		srcs/create_map.c		\
		srcs/set_game.c			\
		srcs/error_handling.c		\

CC	=	gcc -o

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror  -I./include/ -L./lib/my -lmy -g

NAME	=	matchstick

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C lib/my
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
