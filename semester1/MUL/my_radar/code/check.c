/*
** EPITECH PROJECT, 2025
** check.c
** File description:
** check
*/

#include "../include/proto.h"

static int is_a_nbr(int c)
{
    if (c == 0 || c == ' ' || c == '\t' || c == '\n')
        return 1;
    if (c >= '0' && c <= '9')
        return 2;
    else
        return 0;
}

plane_t *checka(char *str, int i, plane_t *plane)
{
    int test = 0;
    int stock[6] = {0, 0, 0, 0, 0, 0};

    for (; str[i] != '\n' && str[i] != 0; i++) {
        if (is_a_nbr(str[i]) == 0)
            return plane;
        if (is_a_nbr(str[i]) == 1 && is_a_nbr(str[i + 1]) == 2)
            test++;
        if (test > 6)
            return plane;
        if (is_a_nbr(str[i]) == 2)
            stock[test - 1] = stock[test - 1] * 10 + str[i] - '0';
    }
    plane = create_plane(stock, plane);
    return plane;
}

tower_t *checkt(char *str, int i, tower_t *tower)
{
    int test = 0;
    int stock[4] = {0, 0, 0, 0};

    for (; str[i] != '\n' && str[i] != 0; i++) {
        if (is_a_nbr(str[i]) == 0)
            return tower;
        if (is_a_nbr(str[i]) == 1 && is_a_nbr(str[i + 1]) == 2)
            test++;
        if (test > 3)
            return tower;
        if (is_a_nbr(str[i]) == 2)
            stock[test - 1] = stock[test - 1] * 10 + str[i] - '0';
    }
    tower = create_tower(stock, tower);
    return tower;
}
