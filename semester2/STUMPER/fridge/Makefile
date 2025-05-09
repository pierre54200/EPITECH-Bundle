##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make
##

SRC=	src/main.c	\
	src/fridge.c	\
	src/disp_cmd.c	\
	src/add_fridge.c	\
	src/make_cmd.c	\
	src/enought_ig.c

OBJ=	${SRC:.c=.o}

CFLAGS= -Wall -Wextra

NAME=	fridge

INCLUDE= -iquote.

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o ${NAME} $(OBJ) ${INCLUDE}

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

.PHONY: re fclean clean all
