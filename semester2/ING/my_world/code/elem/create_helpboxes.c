/*
** EPITECH PROJECT, 2025
** helpboxes.c
** File description:
** helpbox
*/

#include "../../include/proto.h"

void tool_box_tools(world_t *w, int nb)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);
    sfVector2f m = {mouse.x, mouse.y};

    if (nb == POINT) {
        sfSprite_setPosition(w->tools->help_point, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_point, NULL);
    }
    if (nb == SQUARE) {
        sfSprite_setPosition(w->tools->help_square, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_square, NULL);
    }
}

void tool_box(world_t *w, int nb)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);
    sfVector2f m = {mouse.x, mouse.y};

    if (nb == GREEN) {
        sfSprite_setPosition(w->tools->help_green, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_green, NULL);
    }
    if (nb == RED) {
        sfSprite_setPosition(w->tools->help_red, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_red, NULL);
    }
    if (nb == BLUE) {
        sfSprite_setPosition(w->tools->help_blue, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_blue, NULL);
    }
    if (nb == YELLOW) {
        sfSprite_setPosition(w->tools->help_yellow, m);
        sfRenderWindow_drawSprite(w->window, w->tools->help_yellow, NULL);
    }
}

void create_helpbox(world_t *world)
{
    sfVector2f pos = {1, 1};

    world->tools->help_blue = sprite_handler(help_boxes[BLUE], pos, pos);
    world->tools->help_red = sprite_handler(help_boxes[RED], pos, pos);
    world->tools->help_green = sprite_handler(help_boxes[GREEN], pos, pos);
    world->tools->help_yellow = sprite_handler(help_boxes[YELLOW], pos, pos);
    world->tools->help_square = sprite_handler(help_boxes[SQUARE], pos, pos);
    world->tools->help_point = sprite_handler(help_boxes[POINT], pos, pos);
}
