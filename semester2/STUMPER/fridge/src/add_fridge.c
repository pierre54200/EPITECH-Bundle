/*
** EPITECH PROJECT, 2025
** add_fridge.c
** File description:
** add_frige
*/

#include "../proto.h"

static void add_to_fridge_bis(char **cmd, fridge_t *fridge)
{
    if (strcmp(cmd[1], "olive") == 0)
        fridge->olive += atoi(cmd[2]);
    if (strcmp(cmd[1], "pepper") == 0)
        fridge->pepper += atoi(cmd[2]);
    if (strcmp(cmd[1], "ham") == 0)
        fridge->ham += atoi(cmd[2]);
    if (strcmp(cmd[1], "cheese") == 0)
        fridge->cheese += atoi(cmd[2]);
}

void add_to_fridge(char **cmd, fridge_t *fridge)
{
    if (atoi(cmd[2]) == 0)
        return;
    if (strcmp(cmd[1], "tomato") == 0)
        fridge->tomato += atoi(cmd[2]);
    if (strcmp(cmd[1], "dough") == 0)
        fridge->dough += atoi(cmd[2]);
    if (strcmp(cmd[1], "onion") == 0)
        fridge->onion += atoi(cmd[2]);
    if (strcmp(cmd[1], "pasta") == 0)
        fridge->pasta += atoi(cmd[2]);
    add_to_fridge_bis(cmd, fridge);
}
