/*
** EPITECH PROJECT, 2025
** display_options.c
** File description:
** display options
*/

#include "../../include/proto.h"

void check_is_in_rect(world_t *world)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(world->window);
    sfFloatRect text_bounds = sfRectangleShape_getGlobalBounds(
        world->option->text_box);
    sfFloatRect int_bounds = sfRectangleShape_getGlobalBounds(
        world->option->int_box_x);
    sfFloatRect int_bounds_y = sfRectangleShape_getGlobalBounds(
        world->option->int_box_y);

    world->option->is_text = 0;
    world->option->is_int_x = 0;
    world->option->is_int_y = 0;
    if (sfFloatRect_contains(&text_bounds, m.x, m.y))
        world->option->is_text = 1;
    if (sfFloatRect_contains(&int_bounds, m.x, m.y))
        world->option->is_int_x = 1;
    if (sfFloatRect_contains(&int_bounds_y, m.x, m.y))
        world->option->is_int_y = 1;
}

static void write_in_input_text(char c, world_t *world)
{
    if (c == '\b') {
        if (world->option->text_len > 0) {
            world->option->input_text[world->option->text_len - 1] = '\0';
            world->option->text_len--;
        }
    } else if (world->option->text_len < MAX_TEXT_LENGTH &&
        c != '\n' && c != ' ') {
        world->option->input_text[world->option->text_len] = c;
        world->option->input_text[world->option->text_len + 1] = '\0';
        world->option->text_len++;
    }
}

static void write_in_input_int_x(char c, world_t *world)
{
    if (c == '\b') {
        if (world->option->int_len_x > 0) {
            world->option->input_int_x[world->option->int_len_x - 1] = '\0';
            world->option->int_len_x--;
        }
    } else if (c >= '0' && c <= '9' &&
        world->option->int_len_x < MAX_INT_LENGTH && c != '\n' && c != ' ') {
        world->option->input_int_x[world->option->int_len_x] = c;
        world->option->input_int_x[world->option->int_len_x + 1] = '\0';
        world->option->int_len_x++;
    }
}

static void write_in_input_int_y(char c, world_t *world)
{
    if (c == '\b') {
        if (world->option->int_len_y > 0) {
            world->option->input_int_y[world->option->int_len_y - 1] = '\0';
            world->option->int_len_y--;
        }
    } else if (c >= '0' && c <= '9' &&
        world->option->int_len_y < MAX_INT_LENGTH && c != '\n' && c != ' ') {
        world->option->input_int_y[world->option->int_len_y] = c;
        world->option->input_int_y[world->option->int_len_y + 1] = '\0';
        world->option->int_len_y++;
    }
}

static void check_wich_to_write(world_t *world, char c)
{
    if (world->option->is_text && world->event.type == sfEvtTextEntered) {
        if (world->event.text.unicode < 128) {
            c = world->event.text.unicode;
            write_in_input_text(c, world);
        }
    }
    if (world->option->is_int_x && world->event.type == sfEvtTextEntered) {
        if (world->event.text.unicode < 128) {
            c = world->event.text.unicode;
            write_in_input_int_x(c, world);
        }
    }
    if (world->option->is_int_y && world->event.type == sfEvtTextEntered) {
        if (world->event.text.unicode < 128) {
            c = world->event.text.unicode;
            write_in_input_int_y(c, world);
        }
    }
}

static void check_click_on_write(world_t *world)
{
    char c = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_is_in_rect(world);
    check_wich_to_write(world, c);
    sfText_setString(world->option->text, world->option->input_text);
    sfText_setString(world->option->int_text_x, world->option->input_int_x);
    sfText_setString(world->option->int_text_y, world->option->input_int_y);
    create_bound(world);
}

void display_options(world_t *world)
{
    check_click_on_write(world);
    sfRenderWindow_drawRectangleShape(world->window,
        world->option->text_box, NULL);
    sfRenderWindow_drawRectangleShape(world->window,
        world->option->int_box_x, NULL);
    sfRenderWindow_drawRectangleShape(world->window,
        world->option->int_box_y, NULL);
    sfRenderWindow_drawText(world->window, world->option->text, NULL);
    sfRenderWindow_drawText(world->window, world->option->int_text_x, NULL);
    sfRenderWindow_drawText(world->window, world->option->int_text_y, NULL);
    sfRenderWindow_drawSprite(world->window, world->option->sc1, NULL);
    sfRenderWindow_drawSprite(world->window, world->option->sc2, NULL);
    return;
}
