/*
** EPITECH PROJECT, 2025
** create_tools.c
** File description:
** tools
*/

#include "../../include/proto.h"

void create_tools(world_t *world)
{
    sfVector2f pos = {20, 20};
    sfVector2f scale = {1, 1};

    world->tools->green = sprite_handler(tools[GREEN], pos, scale);
    pos.x = 60;
    world->tools->blue = sprite_handler(tools[BLUE], pos, scale);
    pos.x = 100;
    world->tools->red = sprite_handler(tools[RED], pos, scale);
    pos.x = 140;
    world->tools->yellow = sprite_handler(tools[YELLOW], pos, scale);
    pos.x = 300;
    world->tools->square = sprite_handler(tools[SQUARE], pos, scale);
    pos.x = 360;
    world->tools->point = sprite_handler(tools[POINT], pos, scale);
}
