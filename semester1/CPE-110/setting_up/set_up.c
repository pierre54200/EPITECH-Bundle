/*
** EPITECH PROJECT, 2024
** set_up.h
** File description:
** setup
*/
#include "setting.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

static char **clean_tab(char **tab, int h, int l)
{
    for (int i = 0; i != h + 1; i++) {
        for (int j = 0; j != l + 1; j++)
            tab[i][j] = 0;
    }
    return tab;
}

static char charcheck(char map)
{
    if (map != '.' && map != 'x')
        return map;
    return 'x';
}

static int verifyx(char **map, int i, int j, int size)
{
    int test = 0;

    for (int k = 0; k != size && test == 0; k++) {
        for (int e = 0; e != size && test == 0; e++){
            test = charcheck(map[i + k][j + e]);
            map[i + k][j + e] = test;
            test = test - 'x';
        }
    }
    return test;
}

static int verify(char **map, int i, int j, int size)
{
    int test = 0;

    for (int k = 0; k != size && test == 0; k++) {
        for (int e = 0; e != size && test == 0; e++){
            test = charcheck(map[i + k][j + e]) - 'x';
        }
    }
    return test;
}

static int square(char **map, int i, int j)
{
    int size = 0;
    int test = 0;

    while (test == 0) {
        test = verify(map, i, j, size);
        size++;
    }
    return size;
}

static int new_map(char **map, int *stock, int h)
{
    int size = 0;
    int test = 0;
    int i = stock[0];
    int j = stock[1];

    while (test == 0 && size < stock[2]) {
        test = verifyx(map, i, j, size);
        size++;
    }
    for (int i = 0; i != h + 1; i++)
        my_putstr(map[i]);
    return 0;
}

static int *find_biggest_square(int *stock, char **map)
{
    int i = 0;
    int j = 0;
    int size = 0;

    for (; map[i][j] != 0; j++) {
        if (map[i][j] == '.')
            size = square(map, i, j) - 1;
        if (map[i][j] == '\n') {
            i++;
            j = -1;
        }
        if (size > stock[2]) {
            stock[0] = i;
            stock[1] = j;
            stock[2] = size;
        }
    }
    return stock;
}

int set_up(char *stock, int h, int l, int e)
{
    char *map[h + 1];
    int k = 0;
    int stocking[3] = {0, 0, 0};

    for (int i = 0; i != h + 1; i++)
        map[i] = malloc(sizeof(char *) * (l + 1));
    clean_tab(map, h, l);
    for (int i = 0; stock[i] != 0; i++) {
        map[k][e] = stock[i];
        if (stock[i] == '\n') {
            k++;
            e = -1;
        }
        e++;
    }
    find_biggest_square(stocking, map);
    new_map(map, stocking, h);
    for (int i = 0; i != h + 1; i++)
        free(map[i]);
    return 0;
}
