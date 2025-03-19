/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** stumper2 connect4
*/

#include "../proto.h"

int my_error(const char *str)
{
    return write(2, str, strlen(str));
}

static int flags_player(game_t *game, const char *av[], int i)
{
    if (strcmp("-p1", av[i]) == 0
        && strlen(av[i + 1]) == 1 && isprint(av[i + 1][0])) {
        game->player1 = av[i + 1][0];
        return 0;
    }
    if (strcmp("-p2", av[i]) == 0 && strlen(av[i + 1]) == 1
        && isprint(av[i + 1][0])) {
        game->player2 = av[i + 1][0];
        return 0;
    }
    if (strcmp("-a", av[i]) == 0 && strlen(av[i + 1]) == 1
        && isprint(av[i + 1][0])) {
        game->winner = av[i + 1][0];
        return 0;
    }
    return 1;
}

static int check_good_char(const game_t *game)
{
    if (game->player1 == game->player2) {
        my_error("Players must be different\n");
        return 84;
    }
    if (game->player1 == game->winner || game->player2 == game->winner) {
        my_error("Players must be different than the referee\n");
        return 84;
    }
    return 0;
}

static int check_good_size(const game_t *game)
{
    if (game->width < 0 && game->height < 0) {
        my_error("Invalid size\n");
        return 84;
    }
    if (game->width > 80) {
        my_error("Invalid width\n");
        return 84;
    }
    if (game->height > 16) {
        my_error("Invalid height\n");
        return 84;
    }
    if ((game->width * game->height) < 20) {
        my_error("Invalid size\n");
        return 84;
    }
    return 0;
}

static nb_arg_t *init_nb(void)
{
    nb_arg_t *nb_arg = malloc(sizeof(nb_arg_t));

    nb_arg->w = 0;
    nb_arg->h = 0;
    nb_arg->p1 = 0;
    nb_arg->p2 = 0;
    nb_arg->a = 0;
    return nb_arg;
}

static int check_nb_args(const char *av[])
{
    nb_arg_t *nb = init_nb();

    for (int i = 1; av[i] != NULL; i = i + 2) {
        if (strcmp("-w", av[i]) == 0)
            nb->w++;
        if (strcmp("-h", av[i]) == 0)
            nb->h++;
        if (strcmp("-p1", av[i]) == 0)
            nb->p1++;
        if (strcmp("-p2", av[i]) == 0)
            nb->p2++;
        if (strcmp("-a", av[i]) == 0)
            nb->a++;
    }
    if (nb->w > 1 || nb->h > 1 || nb->p1 > 1 || nb->p2 > 1 || nb->a > 1) {
        free(nb);
        return 84;
    }
    free(nb);
    return 0;
}

static int manage_check(const game_t *game, const char *av[])
{
    if (check_good_char(game) == 84)
        return 84;
    if (check_good_size(game) == 84)
        return 84;
    if (check_nb_args(av) == 84)
        return 84;
    return 0;
}

static int flags(game_t *game, const char *av[])
{
    for (int i = 1; av[i] != NULL; i = i + 2) {
        if (strcmp("-w", av[i]) == 0 && atoi(av[i + 1]) != 0) {
            game->width = atoi(av[i + 1]);
            continue;
        }
        if (strcmp("-h", av[i]) == 0 && atoi(av[i + 1]) != 0) {
            game->height = atoi(av[i + 1]);
            continue;
        }
        if (flags_player(game, av, i) == 0)
            continue;
        my_error("Invalid arguments\n");
        return 84;
    }
    if (manage_check(game, av) == 84)
        return 84;
    return 0;
}

int error_handling(game_t *game, int ac, const char *av[])
{
    if (ac > 11) {
        my_error("Too much arguments\n");
        return 84;
    }
    if (ac % 2 == 0) {
        my_error("Wrong number of arguments\n");
        return 84;
    }
    if (flags(game, av) == 84) {
        return 84;
    }
    return 0;
}
