/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/
#include "duck.h"

int main(int ac, char **av)
{
    game_t game;

    game.menu.code = 0;
    if (ac == 1) {
        my_hunter(game);
        return 0;
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            printf("This game is a very famous shooting game from the NES.\n");
            printf("\nYou have to kill as many duck as possible with ");
            printf("your mouse.\nYou can also choose the difficulty.\n");
            printf("\nHave fun with the game\n");
            return 0;
        }
        return 84;
    }
    if (ac > 2)
        return 84;
}
