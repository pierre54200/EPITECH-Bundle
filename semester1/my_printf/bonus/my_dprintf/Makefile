##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

CFLAGS = -g

all:	$(NAME)

$(NAME):	$(OBJ)
	rm -f $(NAME)
	rm -f *.a
	ar cr libmy.a $(SRC)
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f '*.o'
	rm -f *.o

clean:
	rm -f a.out
	rm -f $(OBJ)
	rm -f $(NAME)

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
	ar cr libmy.a $(SRC)
	gcc -Wall -Wextra -o mouli $(OBJ) -I. -L -lmy
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f '*.o'
	rm -f *.o
