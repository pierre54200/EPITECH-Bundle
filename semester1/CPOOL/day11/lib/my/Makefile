##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC = $(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	test

CFLAGS = -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a *.o
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f a.out
	rm -f '*.o'
	rm -f *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f libmy.a

re:	fclean all
