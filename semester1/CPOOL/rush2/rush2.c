/*
** EPITECH PROJECT, 2024
** rush2
** File description:
** count number of char
*/
#include <unistd.h>
#include "include/my.h"

static int nbletter_calc(char **av, char letter)
{
    int nb_letter = 0;

    for (int n = 0; av[1][n] != 0; n++) {
        if ((av[1][n] == (letter + 32) || av[1][n] == (letter - 32))
            && (av[1][n] >= 'A' && av[1][n] <= 'z'))
            nb_letter++;
        if (av[1][n] == letter)
            nb_letter++;
    }
    return nb_letter;
}

static int language(char **av)
{
    if (nbletter_calc(av, 't') >= nbletter_calc(av, 'a')
    || (nbletter_calc(av, 'h') >= nbletter_calc(av, 'a'))) {
        write(1, "=> English", 10);
        return 0;
    }
    if (nbletter_calc(av, 'n') >= nbletter_calc(av, 'a')
    || (nbletter_calc(av, 'r') >= nbletter_calc(av, 'a'))) {
        write(1, "=> German", 9);
        return 0;
    }
    if (nbletter_calc(av, 's') >= nbletter_calc(av, 'a')
    || (nbletter_calc(av, 'm') >= nbletter_calc(av, 'a'))) {
        write(1, "=> French", 9);
        return 0;
    }
    write(1, "=> Spanish", 10);
    return 0;
}

int percentage(char **av, int nb)
{
    int value = 0;
    int len = 0;

    for (int i = 0; av[1][i] != 0; i++) {
        if (is_a_char(av[1][i]) == 0)
            len++;
    }
    value = (nb * 10000 / len);
    write(1, " (", 2);
    my_put_nbr(value / 100);
    write(1, ".", 1);
    if (value % 100 >= 10)
        my_put_nbr(value % 100);
    if (value % 100 < 10) {
        write(1, "0", 1);
        my_put_nbr(value % 100);
    }
    write(1, "%)", 2);
    return 0;
}

int occurrences(int ac, char **av, int i)
{
    int nb_letter = 0;

    for (int n = 0; av[1][n] != 0; n++) {
        if ((av[1][n] == (av[i][0] + 32) || av[1][n] == (av[i][0] - 32))
            && (av[1][n] >= 'A' && av[1][n] <= 'z'))
            nb_letter++;
        if (av[1][n] == av[i][0])
            nb_letter++;
    }
    return nb_letter;
}

int result(int ac, char **av, int nb)
{
    for (int i = 2; i < ac; i++) {
        if (av[i][1] != 0)
            return 84;
        if (is_a_char(av[i][0]) != 0)
            return 84;
    }
    for (int i = 2; i < ac; i++) {
        if (av[i][1] != 0)
            return 84;
        if (is_a_char(av[i][0]) != 0)
            return 84;
        nb = occurrences(ac, av, i);
        write(1, av[i], 1);
        my_putchar(':');
        my_put_nbr(nb);
        percentage(av, nb);
        my_putchar('\n');
    }
    language(av);
        return 0;
}

int main(int ac, char **av)
{
    int nb = 0;

    if (ac < 3)
        return 84;
    result(ac, av, nb);
    return 0;
}
