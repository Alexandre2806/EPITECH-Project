##
## EPITECH PROJECT, 2024
## make
## File description:
## make
##

LIB = lib/my/libmy.a

SRC = mysh.c \

NAME = mysh

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -Iinclude -Llib/my -lmy -g

$(NAME): $(LIB) $(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

PHONY: clean fclean re

$(LIB):
		make -C lib/my

clean:
		rm $(OBJ)
		make -C lib/my clean

fclean: clean
		rm $(NAME)
		make -C lib/my fclean

re: fclean all
