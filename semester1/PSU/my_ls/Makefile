##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	my_ls

CFLAGS = -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	rm -f $(NAME)
	rm -f *.a
	make -C lib/my
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -I./include -L./lib/my -lmy
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
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -g
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f a.out
	rm -f '*.o'
	./$(NAME)
	@echo "\n"
