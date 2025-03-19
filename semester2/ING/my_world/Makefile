##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC =	$(wildcard code/*/*.c) \
		$(wildcard code/*.c)

OBJ = $(SRC:.c=.o)

NAME =	my_world

CFLAGS = -Wall -Wextra -Ofast

FLAGS = -lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio -lm

INCLUDE = -I./include

all: $(NAME)

$(NAME): fclean $(OBJ) clean
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(FLAGS)

pierre: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(FLAGS)
	./$(NAME)

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

do:	fclean $(NAME) reclean
	./$(NAME)

.PHONY: clean reclean re fclean
