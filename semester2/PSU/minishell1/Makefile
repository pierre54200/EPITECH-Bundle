##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard code/*.c) $(wildcard code/built_in/*.c)

OBJ =	$(SRC:.c=.o)

NAME =	mysh

CFLAGS = -g -Wall -Wextra

INCLUDE = -I./include

all: fclean $(NAME) reclean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE)

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

tests_run: fclean
	cp -r ./tests/bashtest/ .
	./tests/test.sh
	rm -r ./bashtest/
