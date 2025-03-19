/*
** EPITECH PROJECT, 2025
** display.c
** File description:
** display
*/

#include "../../include/proto.h"

void display(world_t *world)
{
    display_menu(world);
    sfRenderWindow_display(world->window);
    sfRenderWindow_clear(world->window, sfBlack);
}
