/*
** EPITECH PROJECT, 2025
** buttons.c
** File description:
** buttons
*/

#include "../../include/proto.h"

static int is_on_button(world_t *world, sfSprite *button, sfColor color)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfFloatRect button_pos = sfSprite_getGlobalBounds(button);
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};
    int value = 0;

    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
        sfSprite_setColor(button, color);
        value = 1;
    } else
        sfSprite_setColor(button, sfWhite);
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)
    && sfMouse_isButtonPressed(sfMouseLeft) == 1)
        value = 2;
    return value;
}

static int is_on_button_pressed_tools(world_t *world,
    sfSprite *button, sfColor color, int nb)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfFloatRect button_pos = sfSprite_getGlobalBounds(button);
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};
    int value = 0;

    if (nb == world->tools->current_tool)
        return 0;
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
        tool_box_tools(world, nb);
        sfSprite_setColor(button, color);
        value = 1;
    } else
        sfSprite_setColor(button, sfWhite);
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)
    && sfMouse_isButtonPressed(sfMouseLeft) == 1)
        value = 2;
    return value;
}

static int is_on_button_pressed(world_t *world,
    sfSprite *button, sfColor color, int nb)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfFloatRect button_pos = sfSprite_getGlobalBounds(button);
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};
    int value = 0;

    if (nb == world->tools->color_id)
        return 0;
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)) {
        tool_box(world, nb);
        sfSprite_setColor(button, color);
        value = 1;
    } else
        sfSprite_setColor(button, sfWhite);
    if (sfFloatRect_intersects(&button_pos, &mouse_pos, NULL)
    && sfMouse_isButtonPressed(sfMouseLeft) == 1)
        value = 2;
    return value;
}

static void is_pressed_tools(world_t *world, sfSprite *button)
{
    sfSprite_setColor(world->tools->square, sfWhite);
    sfSprite_setColor(world->tools->point, sfWhite);
    sfSprite_setColor(button, sfBlack);
}

static void is_pressed(world_t *world, sfSprite *button)
{
    sfSprite_setColor(world->tools->green, sfGreen);
    sfSprite_setColor(world->tools->yellow, sfYellow);
    sfSprite_setColor(world->tools->blue, sfBlue);
    sfSprite_setColor(world->tools->red, sfRed);
    sfSprite_setColor(button, sfBlack);
}

void buttons_menu(world_t *world)
{
    if (is_on_button(world, world->menu->world, sfRed) == 2)
        world->menu->menu_status = WORLD;
    if (is_on_button(world, world->menu->settings, sfRed) == 2)
        world->menu->menu_status = OPTIONS;
    if (is_on_button(world, world->menu->exit, sfRed) == 2)
        sfRenderWindow_close(world->window);
}

static void button_color(world_t *world)
{
    if (world->tools->color_id == GREEN)
        is_pressed(world, world->tools->green);
    if (world->tools->color_id == RED)
        is_pressed(world, world->tools->red);
    if (world->tools->color_id == BLUE)
        is_pressed(world, world->tools->blue);
    if (world->tools->color_id == YELLOW)
        is_pressed(world, world->tools->yellow);
    if (world->tools->current_tool == POINT)
        is_pressed_tools(world, world->tools->point);
    if (world->tools->current_tool == SQUARE)
        is_pressed_tools(world, world->tools->square);
}

static void buttons_tools(world_t *world)
{
    if (is_on_button_pressed_tools(world,
        world->tools->point, sfRed, POINT) == 2)
        world->tools->current_tool = POINT;
    if (is_on_button_pressed_tools(world,
        world->tools->square, sfRed, SQUARE) == 2)
        world->tools->current_tool = SQUARE;
}

static void rest_buttons_world(world_t *world)
{
    if (is_on_button_pressed(world, world->tools->blue, sfRed, BLUE) == 2) {
        world->tools->color_id = BLUE;
        world->tools->color = sfBlue;
        world->tools->cursor = sfRed;
    }
    if (is_on_button_pressed(world, world->tools->yellow,
        sfRed, YELLOW) == 2) {
        world->tools->color_id = YELLOW;
        world->tools->color = sfYellow;
        world->tools->cursor = sfRed;
    }
}

void buttons_world(world_t *world)
{
    button_color(world);
    if (is_on_button(world, world->menu->menu, sfRed) == 2)
        world->menu->menu_status = MENU;
    if (is_on_button_pressed(world, world->tools->green, sfRed, GREEN) == 2) {
        world->tools->color_id = GREEN;
        world->tools->color = sfWhite;
        world->tools->cursor = sfRed;
    }
    if (is_on_button_pressed(world, world->tools->red, sfBlue, RED) == 2) {
        world->tools->color_id = RED;
        world->tools->color = sfRed;
        world->tools->cursor = sfGreen;
    }
    rest_buttons_world(world);
    buttons_tools(world);
}
