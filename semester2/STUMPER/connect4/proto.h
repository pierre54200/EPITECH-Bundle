/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** proto
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct game_s {
    int width;
    int height;
    char player1;
    char player2;
    char winner;
    int **map;
    char player;
    int win;
} game_t;

typedef struct nb_arg_s {
    int w;
    int h;
    int p1;
    int p2;
    int a;
} nb_arg_t;

#ifndef PROTO_H
    #define PROTO_H
int connect(game_t *game);
int error_handling(game_t *game, int ac, const char *av[]);
int my_error(const char *str);
int algo(game_t *game, int nb);
#endif // PROTO_H //
