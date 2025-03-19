/*
** EPITECH PROJECT, 2025
** create_menu.c
** File description:
** create menu
*/

#include "../../include/proto.h"

void create_menu(world_t *world)
{
    sfVector2f pos = {400, 100};
    sfVector2f scale = {1, 1};

    world->menu->world = sprite_handler(menu[0], pos, scale);
    pos.y = 250;
    world->menu->settings = sprite_handler(menu[1], pos, scale);
    pos.y = 400;
    world->menu->exit = sprite_handler(menu[2], pos, scale);
    pos.x = 750;
    pos.y = 30;
    world->menu->menu = sprite_handler(menu[3], pos, scale);
}
