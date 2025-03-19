/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "../../include/proto.h"

static int my_world_h(int exit)
{
    printf("------------------My_World-------------------\n\n");
    printf("ZHOU Victor                MACIEJEWSKI Pierre\n\n");
    printf("-----------------Description-----------------\n\n");
    printf("Map terraformer program:\n");
    printf("You can display a map and edit it at runtime.\n\n");
    printf("---------------------------------------------\n");
    return exit;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return my_world();
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return my_world_h(0);
    return my_world_h(84);
}
