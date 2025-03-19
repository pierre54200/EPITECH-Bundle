/*
** EPITECH PROJECT, 2025
** event.c
** File description:
** event
*/

#include "../../include/proto.h"

int timer_for_key_pressed(sfClock *clock, int timer)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (time.microseconds >= timer) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

static void symetric_type(world_t *world)
{
    if (world->tools->symetric == 0 && sfKeyboard_isKeyPressed(sfKeyF)
    && timer_for_key_pressed(world->clock_escape, 50000) == 1) {
        world->tools->symetric = 1;
        return;
    }
    if (world->tools->symetric == 1 && sfKeyboard_isKeyPressed(sfKeyF)
    && timer_for_key_pressed(world->clock_escape, 50000) == 1) {
        world->tools->symetric = 0;
        return;
    }
}

static void key_type(world_t *world)
{
    if (world->menu->menu_status == WORLD) {
        world->menu->menu_status = MENU;
        return;
    }
    if (world->menu->menu_status == MENU) {
        world->menu->menu_status = WORLD;
        return;
    }
    if (world->menu->menu_status == OPTIONS) {
        world->menu->menu_status = WORLD;
    }
}

static void key_move(world_t *world)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        world->vertical -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        world->vertical += 1;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        world->horizontal -= 20;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        world->horizontal += 20;
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        world->zoom = 1;
        world->angle.x = 0;
        world->angle.y = 0;
        world->vertical = 0;
        world->horizontal = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyW)
    && sfKeyboard_isKeyPressed(sfKeyLControl))
        reset(world);
}

static void key_pressed_for_angle(world_t *world, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyD))
        world->angle.x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        world->angle.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && world->angle.y > -0.20)
        world->angle.y -= 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyS) && world->angle.y < 0.60)
        world->angle.y += 0.01;
    if (event.mouseWheel.delta == 1 && world->zoom < 60)
        world->zoom += 2;
    if (event.mouseWheel.delta == -1 && world->zoom > -20)
        world->zoom -= 2;
    if (sfKeyboard_isKeyPressed(sfKeyEscape)
    && timer_for_key_pressed(world->clock_escape, 300000))
        key_type(world);
    key_move(world);
}

static void key_pressed_color(world_t *world)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        world->tools->color_id = GREEN;
        world->tools->color = sfWhite;
        world->tools->cursor = sfRed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        world->tools->color_id = BLUE;
        world->tools->color = sfBlue;
        world->tools->cursor = sfRed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
        world->tools->color_id = RED;
        world->tools->color = sfRed;
        world->tools->cursor = sfGreen;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) {
        world->tools->color_id = YELLOW;
        world->tools->color = sfYellow;
        world->tools->cursor = sfRed;
    }
}

static void key_pressed(world_t *world, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyL)
    && sfKeyboard_isKeyPressed(sfKeyLControl)
    && timer_for_key_pressed(world->clock_escape, 50000))
        load_map(world);
    key_pressed_for_angle(world, event);
    if (sfKeyboard_isKeyPressed(sfKeyLControl)
    && sfKeyboard_isKeyPressed(sfKeyX))
        sfRenderWindow_close(world->window);
    if (sfKeyboard_isKeyPressed(sfKeyLControl)
    && sfKeyboard_isKeyPressed(sfKeyS))
        save_map(world);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        world->tools->current_tool = POINT;
    if (sfKeyboard_isKeyPressed(sfKeyT))
        world->tools->current_tool = SQUARE;
    key_pressed_color(world);
    symetric_type(world);
}

int event(world_t *world)
{
    sfEvent event = {0};

    world->event = event;
    while (sfRenderWindow_pollEvent(world->window, &world->event)) {
        if (world->event.type == sfEvtClosed)
            sfRenderWindow_close(world->window);
        if (timer_for_key_pressed(world->clock, 1000) == 1)
            key_pressed(world, world->event);
    }
    return 0;
}
