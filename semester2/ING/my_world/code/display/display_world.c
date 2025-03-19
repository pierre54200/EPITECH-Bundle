/*
** EPITECH PROJECT, 2025
** display_world.c
** File description:
** display world
*/

#include "../../include/proto.h"

void display_world(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->menu->menu, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->green, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->blue, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->red, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->yellow, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->square, NULL);
    sfRenderWindow_drawSprite(world->window, world->tools->point, NULL);
    display_map(world);
}
