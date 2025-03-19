/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/
#include "./my.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("\n");
        return 0;
    }
    if (ac > 2)
        return 84;
    return countword(av[1]);
}
