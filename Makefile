##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## the makefile
##

SRC	=	src/main.c			\
		lib/conv_array.c		\
		lib/my_get_nbr.c		\
		lib/my_puto.c			\
		lib/my_strisnum.c		\
		lib/my_strncmp.c		\
		lib/my_str_isalpha.c		\
		src/graph/get_it_init.c		\
		src/graph/parsit.c		\
		src/graph/validate_maker.c	\
		src/algo/algo.c			\
		src/algo/algo2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	= 	-W -Wall -Wextra -Werror -I./inc

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
