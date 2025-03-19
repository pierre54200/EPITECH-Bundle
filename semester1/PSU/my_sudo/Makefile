##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard code/*.c)

OBJ =	$(SRC:.c=.o)

NAME =	my_sudo

CFLAGS = -g -Wall -Wextra

INCLUDE = -I./include

LIB = -lcrypt

all: fclean $(NAME) reclean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LIB)
	chmod u+s $(NAME)

clean:
	rm -f *.a
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)

reclean:
	rm -f *.a
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)
	rm -f lib/my/libmy.a

fclean:	clean
	rm -f $(NAME)

re:	fclean all

do:	fclean
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(LIB)
	./$(NAME)
	fclean
