/*
** EPITECH PROJECT, 2025
** create_menu.c
** File description:
** create menu
*/

#include "../../include/proto.h"

static void base_text(world_t *world)
{
    for (int i = 0; "name"[i] != 0; i++)
        world->option->input_text[i] = "name"[i];
    for (int i = 4; world->option->input_text[i] != 0; i++)
    world->option->input_text[i] = 0;
    world->option->input_int_y[0] = 'y';
    for (int i = 1; world->option->input_int_y[i] != 0; i++)
        world->option->input_int_y[i] = 0;
    world->option->input_int_x[0] = 'x';
    for (int i = 1; world->option->input_int_x[i] != 0; i++)
        world->option->input_int_x[i] = 0;
}

static sfRectangleShape *create_rect(sfVector2f pos)
{
    sfRectangleShape *text_box = sfRectangleShape_create();

    sfRectangleShape_setSize(text_box, (sfVector2f) {400, 50});
    sfRectangleShape_setFillColor(text_box, sfWhite);
    sfRectangleShape_setOutlineColor(text_box,
        sfColor_fromRGB(128, 128, 128));
    sfRectangleShape_setOutlineThickness(text_box, 3);
    sfRectangleShape_setPosition(text_box, pos);
    return text_box;
}

static void create_text(world_t *world)
{
    world->option->font = sfFont_createFromFile(FONT);
    world->option->text = sfText_create();
    world->option->int_text_x = sfText_create();
    world->option->int_text_y = sfText_create();
    sfText_setFont(world->option->text, world->option->font);
    sfText_setCharacterSize(world->option->text, 30);
    sfText_setColor(world->option->text, sfBlack);
    sfText_setFont(world->option->int_text_x, world->option->font);
    sfText_setCharacterSize(world->option->int_text_x, 30);
    sfText_setColor(world->option->int_text_x, sfBlack);
    sfText_setFont(world->option->int_text_y, world->option->font);
    sfText_setCharacterSize(world->option->int_text_y, 30);
    sfText_setColor(world->option->int_text_y, sfBlack);
}

static void create_bound_int_x(world_t *world)
{
    world->option->int_bound_x = sfText_getGlobalBounds(
        world->option->int_text_x);
    world->option->int_width_x = world->option->int_bound_x.width;
    world->option->int_height_x = world->option->int_bound_x.height;
    world->option->int_pos_x = sfRectangleShape_getPosition(
        world->option->int_box_x);
    sfText_setPosition(world->option->int_text_x, (sfVector2f)
        {world->option->int_pos_x.x +
        (sfRectangleShape_getSize(world->option->int_box_x).x -
        world->option->int_width_x) / 2,
        world->option->int_pos_x.y +
        (sfRectangleShape_getSize(world->option->int_box_x).y -
        world->option->int_height_x) / 2});
}

static void create_bound_int_y(world_t *world)
{
    world->option->int_bound_y = sfText_getGlobalBounds(
        world->option->int_text_y);
    world->option->int_width_y = world->option->int_bound_y.width;
    world->option->int_height_y = world->option->int_bound_y.height;
    world->option->int_pos_y = sfRectangleShape_getPosition(
        world->option->int_box_y);
    sfText_setPosition(world->option->int_text_y, (sfVector2f)
        {world->option->int_pos_y.x +
        (sfRectangleShape_getSize(world->option->int_box_y).x -
        world->option->int_width_y) / 2,
        world->option->int_pos_y.y +
        (sfRectangleShape_getSize(world->option->int_box_y).y -
        world->option->int_height_y) / 2});
}

void create_bound(world_t *world)
{
    world->option->text_bound = sfText_getGlobalBounds(world->option->text);
    world->option->text_width = world->option->text_bound.width;
    world->option->text_height = world->option->text_bound.height;
    world->option->text_pos = sfRectangleShape_getPosition(
        world->option->text_box);
    sfText_setPosition(world->option->text, (sfVector2f)
        {world->option->text_pos.x +
        (sfRectangleShape_getSize(world->option->text_box).x -
        world->option->text_width) / 2,
        world->option->text_pos.y +
        (sfRectangleShape_getSize(world->option->text_box).y -
        world->option->text_height) / 2});
    create_bound_int_x(world);
    create_bound_int_y(world);
}

void create_shortcut(world_t *world)
{
    sfVector2f pos1 = {165, 500};
    sfVector2f pos2 = {150, 550};
    sfVector2f scale = {1, 1};

    world->option->sc1 = sprite_handler(shortcut[0], pos1, scale);
    world->option->sc2 = sprite_handler(shortcut[1], pos2, scale);
}

void create_option(world_t *world)
{
    strcpy(world->option->input_text, "");
    strcpy(world->option->input_int_x, "");
    strcpy(world->option->input_int_y, "");
    world->option->text_len = 0;
    world->option->int_len_x = 0;
    world->option->int_len_y = 0;
    world->option->is_text = 0;
    world->option->is_int_x = 0;
    world->option->is_int_y = 0;
    create_text(world);
    world->option->text_box = create_rect((sfVector2f) {200, 100});
    world->option->int_box_x = create_rect((sfVector2f) {200, 200});
    world->option->int_box_y = create_rect((sfVector2f) {200, 300});
    create_bound(world);
    base_text(world);
    create_shortcut(world);
}
