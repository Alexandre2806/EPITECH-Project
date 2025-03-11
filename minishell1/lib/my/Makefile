##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

#include <unistd.h>
#include <stdio.h>

SRC	=	my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strncmp.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	cp $(NAME)

$(NAME): 	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

cp:
	cp my.h ../../include

re: fclean all
