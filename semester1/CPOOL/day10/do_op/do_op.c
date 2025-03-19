/*
** EPITECH PROJECT, 2024
** operator
** File description:
** find the correct operator
*/
#include <unistd.h>
#include "../include/my.h"

static int calculus2(char *av[], int value1, int value2, int nb)
{
    if (av[2][0] == '/') {
        if (value2 == 0) {
            write(2, "Stop: division by zero\n", 22);
            return 0;
        }
        nb = value1 / value2;
    }
    if (av[2][0] == '%') {
        if (value2 == 0) {
            write(2, "Stop: modulo by zero\n", 20);
            return 0;
        }
        nb = value1 % value2;
    }
    return nb;
}

static int calculus(char *av[], int value1, int value2, int nb)
{
    if (av[2][0] == '+')
        nb = value1 + value2;
    if (av[2][0] == '-')
        nb = value1 - value2;
    if (av[2][0] == '*')
        nb = value1 * value2;
    nb = calculus2(av, value1, value2, nb);
    return nb;
}

void main(int ac, char *av[])
{
    int nb = 0;
    int value1 = my_getnbr(av[1]);
    int value2 = my_getnbr(av[3]);

    if (ac != 4)
        return 84;
    if (av[2][0] != '+' && av[2][0] != '-'
    && av[2][0] != '*' && av[2][0] != '/'
    && av[2][0] != '%') {
        my_put_nbr(nb);
        my_putchar('\n');
        return;
    }
    nb = calculus(av, value1, value2, nb);
    my_put_nbr(nb);
    my_putchar('\n');
    return;
}
