##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	rush3

CFLAGS = -g

all:	$(NAME)

$(NAME):	$(OBJ)
	rm -f $(NAME)
	rm -f *.a
	ar rc libmy.a $(OBJ)
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -I. -L -lmy
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f '*.o'
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
	ar rc libmy.a $(OBJ)
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -g
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f a.out
	rm -f '*.o'
	./$(NAME)
	@echo "\n"
