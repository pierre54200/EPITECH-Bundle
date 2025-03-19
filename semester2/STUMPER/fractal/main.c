/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/
#include "proto.h"

static int is_right_chartwo(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != '@') {
            my_puts("wrong arguments character must be");
            my_puts(" . or @ in the second chain\n");
            return 0;
        }
    }
    return 1;
}

static int is_right_char(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != '#' && str[i] != '@') {
            my_puts("wrong arguments character must be");
            my_puts(" . or @ in the first chain\n");
            return 0;
        }
    }
    return 1;
}

static int is_nb(const char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9') {
            my_puts("first argument must be a number > 0\n");
            return 0;
        }
    }
    return 1;
}

int nbr_of_line(const char *av)
{
    int nb = 1;

    for (int i = 0; av[i] != 0; i++) {
        if (av[i] == '@')
            nb++;
    }
    return nb;
}

int nbr_per_line(const char *av)
{
    int nb = 0;
    int test = 0;

    for (; av[nb] != 0 && av[nb] != '@'; nb++);
    for (int i = 0; av[i] != 0; i++) {
        if (av[i] != '@')
            test++;
        if (av[i] == '@' && test != nb)
            return -1;
        if (av[i] == '@')
            test = 0;
    }
    return nb;
}

static int error_handling(char **av)
{
    if (my_strlen(av[2]) == 0 || my_strlen(av[3]) == 0) {
        my_puts("chain must have at least one character\n");
        return 84;
    }
    if (my_strlen(av[2]) != my_strlen(av[3])) {
        my_puts("chain must have the same lenght\n");
        return 84;
    }
    if (nbr_of_line(av[2]) != nbr_of_line(av[3])) {
        my_puts("chain must have the same nmb of @\n");
        return 84;
    }
    if (nbr_per_line(av[2]) != nbr_per_line(av[3])
        && nbr_per_line(av[2]) != -1) {
        my_puts("each line needs to be same size and both ");
        my_puts("chain need to have same size\n");
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 4)
        return 84;
    if (error_handling(av) == 84)
        return 84;
    if (!is_nb(av[1]) || !is_right_char(av[2]) || !is_right_chartwo(av[3]))
        return 84;
    fractal(my_get_nbr(av[1]), av);
    return 0;
}
