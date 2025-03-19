##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make
##

SRC=	src/main.c	\
	src/game.c	\
	src/error.c	\
	src/algo.c

OBJ=	${SRC:.c=.o}

CFLAGS= -Wall -Wextra -Ofast

NAME=	connect4

INCLUDE= -I.

all:	$(OBJ)
	gcc -o ${NAME} ${OBJ} ${INCLUDE}

clean:
	rm -f src/*.o
	rm -f src/*~
	rm -f src/*#
	rm -f *#
	rm -f *~

fclean:	clean
	rm -f ${NAME}

re:	fclean	$(OBJ)
	gcc -o ${NAME} ${OBJ} ${INCLUDE}

.PHONY: re fclean clean
