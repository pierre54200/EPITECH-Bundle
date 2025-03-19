/*
** EPITECH PROJECT, 2025
** game.c
** File description:
** connect4 game
*/

#include "../proto.h"

static int init_map(game_t *game)
{
    game->map = malloc(sizeof(int *) * (game->height));
    if (game->map == NULL)
        return 84;
    for (int i = 0; i != game->height; i++) {
        game->map[i] = malloc(sizeof(int) * (game->width));
        if (game->map[i] == NULL) {
            free(game->map);
            return 84;
        }
        for (int j = 0; j != game->width; j++) {
            game->map[i][j] = 0;
        }
    }
    game->player = game->player1;
    return 0;
}

static void display_cara(game_t *game, int i, int j)
{
    if (game->map[i][j] == 0)
        printf(".");
    if (game->map[i][j] == 1)
        printf("%c", game->player1);
    if (game->map[i][j] == 2)
        printf("%c", game->player2);
    if (game->map[i][j] == 3)
        printf("%c", game->winner);
}

static void display_plus(game_t *game)
{
    for (int i = 0; i < game->width + 2; i++)
        printf("+");
    printf("\n");
}

static void display_map(game_t *game)
{
    for (int i = 0; i != game->height; i++) {
        printf("|");
        for (int j = 0; j != game->width; j++) {
            display_cara(game, i, j);
        }
        printf("|\n");
    }
    return;
}

static int display_game(game_t *game, int nb)
{
    int test = 0;

    test = algo(game, nb);
    display_plus(game);
    display_map(game);
    display_plus(game);
    return test;
}

static char change_player(game_t *game)
{
    if (game->player == game->player1)
        return game->player2;
    if (game->player == game->player2)
        return game->player1;
    return 0;
}

int connect(game_t *game)
{
    char *buffer = NULL;
    size_t size = 2;
    ssize_t nread = 0;

    if (init_map(game) == 84)
        return 84;
    while (game->win != 1) {
        printf("Player %c, where do you want to play: ", game->player);
        nread = getline(&buffer, &size, stdin);
        if (nread < 0)
            break;
        if (atoi(buffer) == 0 || atoi(buffer) > game->width)
            continue;
        if (display_game(game, atoi(buffer)) != 0)
            continue;
        game->player = change_player(game);
    }
    free(buffer);
    return 0;
}
