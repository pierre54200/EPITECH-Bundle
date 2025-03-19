/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** stumper2 connect4
*/

#include "../proto.h"

static game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL) {
        my_error("Can't load game structure\n");
        return NULL;
    }
    game->height = 6;
    game->width = 7;
    game->player1 = 'X';
    game->player2 = 'O';
    game->winner = '#';
    game->win = 0;
    return game;
}

static void display_win(game_t *game)
{
    if (game->win == 1) {
        if (game->player == game->player1)
            printf("Congrats, player %c won!\n", game->player2);
        if (game->player == game->player2)
            printf("Congrats, player %c won!\n", game->player1);
    }
    if (game->win == 2)
        printf("It's a tie, nobody wins.\n");
}

int main(int ac, const char *av[])
{
    game_t *game = init_game();

    if (game == NULL)
        return 84;
    if (error_handling(game, ac, av) == 84) {
        free(game);
        return 84;
    }
    connect(game);
    for (int i = 0; i != game->height; i++)
        free(game->map[i]);
    display_win(game);
    free(game->map);
    free(game);
    return 0;
}
