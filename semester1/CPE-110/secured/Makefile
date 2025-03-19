##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard code/*.c)

OBJ =	$(SRC:.c=.o)

NAME =	secured

CFLAGS = -g -Wall -Wextra

INCLUDE = -I./include

LIB = -L./code -lhashtable

CRITERION = --coverage -lcriterion

all: fclean $(NAME) reclean

$(NAME):	$(OBJ)
	make -C code

do:
	gcc -o $(NAME) main.c $(INCLUDE) $(LIB) $(CFLAGS)

clean:
	rm -f *~
	rm -f *#
	rm -f code/*.o
	rm -f $(OBJ)

reclean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)

fclean:	clean
	rm -f lib/my/*.a
	rm -f libhashtable.a
	rm -f code/libhashtable.a
	rm -f $(NAME)

aclean: clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o $(NAME) tests/test.c $(INCLUDE) $(LIB) $(CFLAGS) $(CRITERION)
	./secured
	rm -f *.gcda
	rm -f *.gcno
