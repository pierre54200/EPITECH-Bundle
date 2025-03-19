##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard code/*.c)

OBJ =	$(SRC:.c=.o)

NAME =	my_radar

CFLAGS = -g -Wall -Wextra

FLAGS = -lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio -lm

INCLUDE = -I./include

all: fclean $(NAME) reclean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(FLAGS)

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

do:	fclean $(NAME) reclean
	./$(NAME)
