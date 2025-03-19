/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "include/proto.h"
#include <ncurses.h>

int main(int ac, char **av)
{
    int refresh = 3;
    char opt[] = "dUn";
    int c = 0;
    char user[20] = "";
    int counter = -1;

    for (int i = 0; c != EOF; i++) {
        c = getopt(ac, av, opt);
        if (c == 'd')
            refresh = my_getnbr(av[i + 2]);
        if (c == 'U')
            my_strcpy(user, av[i + 2]);
        if (c == 'n')
            counter = my_getnbr(av[i + 2]);
    }
    return my_top(refresh, counter);
}
