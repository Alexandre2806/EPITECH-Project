##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC = my_printf.c \
      my_putchar.c \
      my_putnbr.c \
      my_putstr.c \
      my_put_unsigned_nbr.c \
      my_put_octal.c \
      my_put_float.c \
      my_put_hexa.c \
      my_put_pointer.c \
      my_put_e.c \
      my_put_g.c \
      my_put_unsigned_long.c \
      my_put_unsigned_longlong.c \
      find_nbr.c \
      my_put_minus.c \
      my_put_plus.c \
      my_put_zero.c \
      case_e.c \
      case_fi.c \
      case_g.c \
      case_l.c \
      case_minus.c \
      case_ou.c \
      case_p.c \
      case_plus.c \
      case_pourcent.c \
      case_sd.c \
      case_x.c \
      case_zero.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):        $(OBJ)
	ar rc ../../$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re: fclean $(NAME)
