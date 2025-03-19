##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	libhashtable.a

CFLAGS = -g -Wall -Wextra

INCLUDE = -I../include

all: fclean $(NAME) clean

$(NAME):	$(OBJ)
	ar cr $(NAME) $(OBJ)
	cp libhashtable.a ..

clean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)

fclean:	clean
	rm -f *.a
	rm -f $(NAME)

re:	fclean all
