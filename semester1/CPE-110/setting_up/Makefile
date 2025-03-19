##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	setting_up

CFLAGS = -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	rm -f $(NAME)
	rm -f *.a
	gcc -o $(NAME) $(OBJ) -I.
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f *.o

clean:
	rm -f $(OBJ)
	rm -f lib/my/libmy.a

fclean:	clean
	rm -f $(NAME)

re:	fclean all

git:	fclean
	git add *
	@echo "Put your commit"
	read ASW
	git commit -m "$$ASW"
	git push

do:		$(OBJ)
	rm -f $(NAME)
	rm -f *.a
	gcc -o a.out $(OBJ) -I.
	rm -f *~
	rm -f *#
	rm -f *.o
