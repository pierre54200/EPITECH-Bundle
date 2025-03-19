/*
** EPITECH PROJECT, 2025
** display_menu.c
** File description:
** display menu
*/

#include "../../include/proto.h"

static void display_menu_elem(world_t *world)
{
    sfRenderWindow_setView(world->window,
        sfRenderWindow_getDefaultView(world->window));
    buttons_menu(world);
    sfRenderWindow_drawSprite(world->window, world->menu->world, NULL);
    sfRenderWindow_drawSprite(world->window, world->menu->settings, NULL);
    sfRenderWindow_drawSprite(world->window, world->menu->exit, NULL);
    return;
}

void display_menu(world_t *world)
{
    if (world->menu->menu_status == MENU)
        display_menu_elem(world);
    if (world->menu->menu_status == WORLD)
        display_world(world);
    if (world->menu->menu_status == OPTIONS)
        display_options(world);
    return;
}
