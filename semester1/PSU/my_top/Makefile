##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	my_top

CFLAGS = -g -Wall -Wextra

FLAG = -lncurses

all: fclean $(NAME) reclean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I./include $(FLAG)

clean:
	rm -f *.a
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)

reclean:
	rm -f *.a
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f $(OBJ)

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
