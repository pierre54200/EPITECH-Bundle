##
## EPITECH PROJECT, 2024
## D10
## File description:
## D10
##

SRC	=	do_op.c

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -I../include -L../lib/my -lmy

clean:
	rm -f $(OBJ)

fclean: clean

re:	fclean all
