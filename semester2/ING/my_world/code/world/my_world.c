/*
** EPITECH PROJECT, 2025
** my_world.c
** File description:
** my_world
*/

#include "../../include/proto.h"

int my_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    if (world == NULL)
        return 84;
    world->window = mode("Mon_Monde", 800, 600, 240);
    set_my_world(world);
    while (sfRenderWindow_isOpen(world->window)) {
        event(world);
        display(world);
        recreate_map(world);
    }
    sfRenderWindow_destroy(world->window);
    free_world(world);
    return 0;
}
