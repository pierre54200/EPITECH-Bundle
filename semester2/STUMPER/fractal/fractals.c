/*
** EPITECH PROJECT, 2025
** fractals.c
** File description:
** fractals
*/

#include "proto.h"

static void patern_zero(void)
{
    my_putstr("#\n");
}

static void patern_un(const char *av)
{
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] == '@')
            my_putstr("\n");
        if (av[i] != '@')
            my_putchar(av[i]);
    }
    my_putstr("\n");
}

static void patern(char **av)
{
    return;
}

void fractal(int nb, char **av)
{
    if (nb == 0)
        patern_zero();
    if (nb == 1)
        patern_un(av[2]);
    if (nb > 1)
        patern(av);
}
