/*
** EPITECH PROJECT, 2025
** free_world.c
** File description:
** free elem in world
*/

#include "../../include/proto.h"

static void free_tools(world_t *world)
{
    sfSprite_destroy(world->tools->blue);
    sfSprite_destroy(world->tools->green);
    sfSprite_destroy(world->tools->red);
    sfSprite_destroy(world->tools->yellow);
    sfSprite_destroy(world->tools->square);
    sfSprite_destroy(world->tools->point);
    free(world->tools);
}

static void free_menu(world_t *world)
{
    sfSprite_destroy(world->menu->world);
    sfSprite_destroy(world->menu->menu);
    sfSprite_destroy(world->menu->settings);
    sfSprite_destroy(world->menu->exit);
    free(world->menu);
}

static void free_option(world_t *world)
{
    sfFont_destroy(world->option->font);
    sfText_destroy(world->option->text);
    sfText_destroy(world->option->int_text_x);
    sfRectangleShape_destroy(world->option->text_box);
    sfRectangleShape_destroy(world->option->int_box_x);
    free(world->option);
}

void free_world(world_t *world)
{
    free(world->map);
    free(world->map_2d);
    sfClock_destroy(world->clock);
    sfClock_destroy(world->clock_escape);
    free_tools(world);
    free_menu(world);
    free_option(world);
    free(world);
}
