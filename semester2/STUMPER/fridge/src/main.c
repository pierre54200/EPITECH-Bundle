/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** stumper2 connect4
*/

#include "../proto.h"

int main(int ac, const char *const *av)
{
    if (ac > 2)
        return 84;
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        printf("./fridge\n");
    return fridge();
}
