##
## EPITECH PROJECT, 2020
## matchstick
## File description:
## Makefile
##

SRC	=	my_getnbr.c															\
		my_putchar.c														\
		my_putstr.c															\
		my_str_isnum.c														\
		my_put_nbr.c														\
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc	$(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all