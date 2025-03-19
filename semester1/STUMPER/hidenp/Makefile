##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make
##

SRC = ${wildcard *.c}

OBJ = ${SRC:.c=.o}

NAME = hidenp

CFLAGS = -Wall -g -Wextra

all: fclean ${NAME}

${NAME}: ${OBJ}
	gcc -o ${NAME} ${OBJ}

clean:
	rm -f *.o
	rm -f *~
	rm -f *#

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME} clean
