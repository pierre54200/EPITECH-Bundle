/*
** EPITECH PROJECT, 2025
** algo.c
** File description:
** algo for connect4
*/

#include "../proto.h"

static int check_not_tie(game_t *game, int i, int j)
{
    if (game->map[i][j] == 0)
        return 1;
    return 0;
}

static void check_tie(game_t *game)
{
    int test = 0;

    for (int i = 0; i != game->height; i++) {
        for (int j = 0; j != game->width; j++)
            test += check_not_tie(game, i, j);
    }
    if (test != 0)
        return;
    game->win = 3;
}

static void algo_win_diago_inv(game_t *game, int x, int y)
{
    int p = game->map[x][y];

    if (x + 3 < game->height && y - 3 >= 0 && game->map[x + 1][y - 1] == p
        && game->map[x + 2][y - 2] == p && game->map[x + 3][y - 3] == p) {
        game->map[x][y] = 3;
        game->map[x + 1][y - 1] = 3;
        game->map[x + 2][y - 2] = 3;
        game->map[x + 3][y - 3] = 3;
        game->win = 1;
    }
    if (x - 3 >= 0 && y + 3 < game->width && game->map[x - 1][y + 1] == p
        && game->map[x - 2][y + 2] == p && game->map[x - 3][y + 3] == p) {
        game->map[x][y] = 3;
        game->map[x - 1][y + 1] = 3;
        game->map[x - 2][y + 2] = 3;
        game->map[x - 3][y + 3] = 3;
        game->win = 1;
    }
}

static void algo_win_diago(game_t *game, int x, int y)
{
    int p = game->map[x][y];

    if (x + 3 < game->height && y + 3 < game->width
        && game->map[x + 1][y + 1] == p
        && game->map[x + 2][y + 2] == p && game->map[x + 3][y + 3] == p) {
        game->map[x][y] = 3;
        game->map[x + 1][y + 1] = 3;
        game->map[x + 2][y + 2] = 3;
        game->map[x + 3][y + 3] = 3;
        game->win = 1;
    }
    if (x - 3 >= 0 && y - 3 >= 0 && game->map[x - 1][y - 1] == p
        && game->map[x - 2][y - 2] == p && game->map[x - 3][y - 3] == p) {
        game->map[x][y] = 3;
        game->map[x - 1][y - 1] = 3;
        game->map[x - 2][y - 2] = 3;
        game->map[x - 3][y - 3] = 3;
        game->win = 1;
    }
    algo_win_diago_inv(game, x, y);
}

static void algo_win_vert(game_t *game, int x, int y)
{
    int p = game->map[x][y];

    if (x + 3 < game->height && game->map[x + 1][y] == p
        && game->map[x + 2][y] == p && game->map[x + 3][y] == p) {
        game->map[x][y] = 3;
        game->map[x + 1][y] = 3;
        game->map[x + 2][y] = 3;
        game->map[x + 3][y] = 3;
        game->win = 1;
    }
    if (x - 3 >= 0 && game->map[x - 1][y] == p
        && game->map[x - 2][y] == p && game->map[x - 3][y] == p) {
        game->map[x][y] = 3;
        game->map[x - 1][y] = 3;
        game->map[x - 2][y] = 3;
        game->map[x - 3][y] = 3;
        game->win = 1;
    }
    algo_win_diago(game, x, y);
}

static void algo_win(game_t *game, int x, int y)
{
    int p = game->map[x][y];

    if (y + 3 < game->width && game->map[x][y + 1] == p
        && game->map[x][y + 2] == p && game->map[x][y + 3] == p) {
        game->map[x][y] = 3;
        game->map[x][y + 1] = 3;
        game->map[x][y + 2] = 3;
        game->map[x][y + 3] = 3;
        game->win = 1;
    }
    if (y - 3 >= 0 && game->map[x][y - 1] == p
        && game->map[x][y - 2] == p && game->map[x][y - 3] == p) {
        game->map[x][y] = 3;
        game->map[x][y - 1] = 3;
        game->map[x][y - 2] = 3;
        game->map[x][y - 3] = 3;
        game->win = 1;
    }
    algo_win_vert(game, x, y);
}

int algo(game_t *game, int nb)
{
    int test = 1;

    if (game->player == game->player2)
        test = 2;
    for (int i = game->height - 1; i != -2; i--) {
        if (i == -1)
            return 1;
        if (game->map[i][nb - 1] == 0) {
            game->map[i][nb - 1] = test;
            algo_win(game, i, nb - 1);
            break;
        }
    }
    check_tie(game);
    return 0;
}
