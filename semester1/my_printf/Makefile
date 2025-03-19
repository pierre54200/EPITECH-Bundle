##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	rm -f *.a
	ar cr $(NAME) $(OBJ)
	rm -f *.o

clean:
	rm -f a.out
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

do:		$(OBJ) $(NAME)
	gcc -Wall -Wextra main.c -o mouli -I. -L. -lmy
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f '*.o'
	rm -f *.o
