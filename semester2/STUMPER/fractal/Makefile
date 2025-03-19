##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make
##

SRC=	main.c	\
	fractals.c	\
	lib/my_getnbr.c	\
	lib/my_putstr.c	\
	lib/my_strlen.c

OBJ=	${SRC:.c=.o}

CFLAGS=	-g -Wall -Wextra -Ofast

NAME=	fractals

INCLUDE= -I.

all:	$(OBJ)
	gcc -o ${NAME} ${OBJ} ${INCLUDE}

clean:
	rm -f *.o
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f ${NAME}

re:	fclean	$(OBJ)
	gcc -o ${NAME} ${OBJ} ${INCLUDE}
