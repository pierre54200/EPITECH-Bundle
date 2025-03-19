/*
** EPITECH PROJECT, 2025
** check_click.c
** File description:
** check_click
*/

#include "../../include/proto.h"

static void symetric(world_t *world, int pos, int y, int x)
{
    if (pos == 1) {
        world->map_2d[y][x]++;
        if (world->tools->symetric == 1)
            world->map_2d[x][y]++;
    }
    if (pos == -1) {
        world->map_2d[y][x]--;
        if (world->tools->symetric == 1)
            world->map_2d[x][y]--;
    }
    if (timer_for_key_pressed(world->clock_escape, 100000))
        sfSound_play(world->dig);
}

static void check_click(world_t *world, int y, int x, sfVector2f point[4])
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f m = sfRenderWindow_mapPixelToCoords(world->window, mouse, 0);
    sfVector2f p1;
    sfVector2f p2;
    int intersections = 0;

    for (int i = 0; i < 4; i++) {
        p1 = point[i];
        p2 = point[(i + 1) % 4];
        if (((m.y > p1.y) != (m.y > p2.y)) &&
            (m.x < (p2.x - p1.x) * (m.y - p1.y) / (p2.y - p1.y) + p1.x)) {
            intersections++;
        }
    }
    if (intersections % 2 != 0 && sfMouse_isButtonPressed(sfMouseLeft))
        symetric(world, 1, y, x);
    if (intersections % 2 != 0 && sfMouse_isButtonPressed(sfMouseRight))
        symetric(world, -1, y, x);
}

static void select_click(world_t *world, int y, int x, sfVector2f point[4])
{
    if (world->tools->current_tool == POINT)
        check_click(world, y, x, point);
}

static int mouse_on_square(sfVector2f p1, sfVector2f p2,
    sfVector2f m, sfVector2f point[4])
{
    int intersections = 0;

    for (int i = 0; i < 4; i++) {
        p1 = point[i];
        p2 = point[(i + 1) % 4];
        if (((m.y > p1.y) != (m.y > p2.y)) &&
            (m.x < (p2.x - p1.x) * (m.y - p1.y) / (p2.y - p1.y) + p1.x)) {
            intersections++;
        }
    }
    return intersections;
}

void check_click4(world_t *world, int y, int x, sfVector2f point[4])
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f m = sfRenderWindow_mapPixelToCoords(world->window, mouse, 0);
    sfVector2f p1;
    sfVector2f p2;
    int intersections = mouse_on_square(p1, p2, m, point);
    static int was_pressed = 0;

    if (world->tools->current_tool != SQUARE)
        return select_click(world, y, x, point);
    if (intersections % 2 != 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 0) {
            symetric(world, 1, y, x);
            symetric(world, 1, y, x - 1);
            symetric(world, 1, y + 1, x - 1);
            symetric(world, 1, y + 1, x);
            was_pressed = 1;
        }
        if (!sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 1)
            was_pressed = 0;
    }
}

void check_click3(world_t *world, int y, int x, sfVector2f point[4])
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f m = sfRenderWindow_mapPixelToCoords(world->window, mouse, 0);
    sfVector2f p1;
    sfVector2f p2;
    int intersections = mouse_on_square(p1, p2, m, point);
    static int was_pressed = 0;

    if (world->tools->current_tool != SQUARE)
        return select_click(world, y, x, point);
    if (intersections % 2 != 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 0) {
            symetric(world, 1, y, x);
            symetric(world, 1, y, x - 1);
            symetric(world, 1, y + 1, x - 1);
            symetric(world, 1, y + 1, x);
            was_pressed = 1;
        }
        if (!sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 1)
            was_pressed = 0;
    }
}

void check_click2(world_t *world, int y, int x, sfVector2f point[4])
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f m = sfRenderWindow_mapPixelToCoords(world->window, mouse, 0);
    sfVector2f p1;
    sfVector2f p2;
    int intersections = mouse_on_square(p1, p2, m, point);
    static int was_pressed = 0;

    if (world->tools->current_tool != SQUARE)
        return select_click(world, y, x, point);
    if (intersections % 2 != 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 0) {
            symetric(world, 1, y, x + 1);
            symetric(world, 1, y, x + 2);
            symetric(world, 1, y - 1, x + 2);
            symetric(world, 1, y - 1, x + 1);
            was_pressed = 1;
        }
        if (!sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 1)
            was_pressed = 0;
    }
}

void check_click1(world_t *world, int y, int x, sfVector2f point[4])
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f m = sfRenderWindow_mapPixelToCoords(world->window, mouse, 0);
    sfVector2f p1;
    sfVector2f p2;
    int intersections = mouse_on_square(p1, p2, m, point);
    static int was_pressed = 0;

    if (world->tools->current_tool != SQUARE)
        return select_click(world, y, x, point);
    if (intersections % 2 != 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 0) {
            symetric(world, 1, y, x);
            symetric(world, 1, y, x + 1);
            symetric(world, 1, y - 1, x + 1);
            symetric(world, 1, y - 1, x);
            was_pressed = 1;
        }
        if (!sfMouse_isButtonPressed(sfMouseLeft) && was_pressed == 1)
            was_pressed = 0;
    }
}
