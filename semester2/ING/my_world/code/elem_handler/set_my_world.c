/*
** EPITECH PROJECT, 2025
** set_my_world.c
** File description:
** set_world
*/

#include "../../include/proto.h"

static void set_states(world_t *world)
{
    sfTexture *texture;

    world->states = malloc(sizeof(sfRenderStates *) * 4);
    if (world->states == NULL)
        return;
    for (int i = 0; i < 4; i++) {
        texture = sfTexture_createFromFile(tile_textures[i], NULL);
        world->states[i] = malloc(sizeof(sfRenderStates));
        world->states[i]->shader = NULL;
        world->states[i]->transform = sfTransform_Identity;
        world->states[i]->texture = texture;
        world->states[i]->blendMode = sfBlendAlpha;
    }
    create_helpbox(world);
    create_tools(world);
    create_option(world);
    create_sound(world);
    world->angle.y = 0;
}

void set_my_world(world_t *world)
{
    world->mx = 20;
    world->my = 20;
    world->menu = malloc(sizeof(menu_t));
    world->tools = malloc(sizeof(tool_t));
    world->option = malloc(sizeof(option_t));
    if (world->menu == NULL || world->tools == NULL)
        return;
    set_clock(world);
    create_map(world, 0);
    create_menu(world);
    world->menu->menu_status = MENU;
    world->zoom = 0.0;
    world->vertical = 0;
    world->horizontal = 0;
    world->tools->color = sfWhite;
    world->tools->color_id = GREEN;
    world->tools->cursor = sfRed;
    world->tools->current_tool = POINT;
    world->tools->symetric = 0;
    set_states(world);
}
