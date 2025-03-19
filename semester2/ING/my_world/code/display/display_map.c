/*
** EPITECH PROJECT, 2025
** display_map.c
** File description:
** display map
*/
#include "../../include/proto.h"

static int get_alt(world_t *world, int y, int x)
{
    if (world->map_2d[y][x] < 0 && timer(world->clock_water, 500000))
        return 1;
    if (world->map_2d[y][x] < 0 && !timer(world->clock_water, 500000))
        return 3;
    if (world->map_2d[y][x] == 0)
        return 0;
    if (world->map_2d[y][x] > 0)
        return 2;
    return 0;
}

static int mouse_on_array(world_t *world, sfVector2f point[4])
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
    return intersections % 2 != 0;
}

static sfVertexArray *create_line(sfVector2f point[4],
    sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2f p0 = {0, 0};
    sfVector2f p1 = {32, 0};
    sfVector2f p2 = {0, 32};
    sfVector2f p3 = {32, 32};
    sfVertex v1 = {.position = point[0], .texCoords = p0, .color = sfWhite};
    sfVertex v2 = {.position = point[1], .texCoords = p1, .color = color};
    sfVertex v3 = {.position = point[2], .texCoords = p2, .color = sfWhite};
    sfVertex v4 = {.position = point[3], .texCoords = p3, .color = color};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_append(vertex_array, v3);
    sfVertexArray_append(vertex_array, v4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return vertex_array;
}

static sfVertexArray *create_point(sfVector2f point[4], world_t *world)
{
    if (mouse_on_array(world, point))
        return create_line(point, world->tools->cursor);
    else
        return create_line(point, world->tools->color);
}

static void draw_map_quads_1(sfRenderWindow *window,
    sfVector2f **map2d, world_t *world)
{
    sfVertexArray *quad;
    sfVector2f point[4];
    int i = 0;

    for (int y = MY - 1; y > 0; y--) {
        for (int x = MX - 1; x > 0; x--) {
            check_click1(world, y, x, point);
            i = get_alt(world, y, x);
            point[0] = map2d[y][x];
            point[1] = map2d[y][x - 1];
            point[2] = map2d[y - 1][x - 1];
            point[3] = map2d[y - 1][x];
            quad = create_point(point, world);
            sfRenderWindow_drawVertexArray(window, quad, world->states[i]);
            sfVertexArray_destroy(quad);
        }
    }
}

static void draw_map_quads_2(sfRenderWindow *window,
    sfVector2f **map2d, world_t *world)
{
    sfVertexArray *quad;
    sfVector2f point[4];
    int i = 0;

    for (int y = 0; y < MY - 1; y++) {
        for (int x = MX - 1; x > 0; x--) {
            check_click2(world, y + 1, x - 1, point);
            i = get_alt(world, y, x);
            point[0] = map2d[y + 1][x];
            point[1] = map2d[y + 1][x - 1];
            point[2] = map2d[y][x - 1];
            point[3] = map2d[y][x];
            quad = create_point(point, world);
            sfRenderWindow_drawVertexArray(window, quad, world->states[i]);
            sfVertexArray_destroy(quad);
        }
    }
}

static void draw_map_quads_3(sfRenderWindow *window,
    sfVector2f **map2d, world_t *world)
{
    sfVertexArray *quad;
    sfVector2f point[4];
    int i = 0;

    for (int y = 0; y < MY - 1; y++) {
        for (int x = 0; x < MX - 1; x++) {
            check_click3(world, y, x, point);
            i = get_alt(world, y, x);
            point[0] = map2d[y][x];
            point[1] = map2d[y][x + 1];
            point[2] = map2d[y + 1][x + 1];
            point[3] = map2d[y + 1][x];
            quad = create_point(point, world);
            sfRenderWindow_drawVertexArray(window, quad, world->states[i]);
            sfVertexArray_destroy(quad);
        }
    }
}

static void draw_map_quads_4(sfRenderWindow *window,
    sfVector2f **map2d, world_t *world)
{
    sfVertexArray *quad;
    sfVector2f point[4];
    int i = 0;

    for (int y = MY - 1; y > 0; y--) {
        for (int x = 0; x < MX - 1; x++) {
            check_click4(world, y - 1, x, point);
            i = get_alt(world, y, x);
            point[0] = map2d[y - 1][x];
            point[1] = map2d[y - 1][x + 1];
            point[2] = map2d[y][x + 1];
            point[3] = map2d[y][x];
            quad = create_point(point, world);
            sfRenderWindow_drawVertexArray(window, quad, world->states[i]);
            sfVertexArray_destroy(quad);
        }
    }
}

static void draw_2d_map(sfRenderWindow *window,
    sfVector2f **map2d, world_t *world)
{
    if (ANGLE_X + world->angle.x > 360)
        world->angle.x = (int)world->angle.x % 360 - 360;
    if (ANGLE_X + world->angle.x < 0)
        world->angle.x = (int)world->angle.x % 360 + 360;
    if (270 <= ANGLE_X + world->angle.x && ANGLE_X + world->angle.x <= 360) {
        draw_map_quads_1(window, map2d, world);
        return;
    }
    if (180 <= ANGLE_X + world->angle.x && ANGLE_X + world->angle.x < 270) {
        draw_map_quads_2(window, map2d, world);
        return;
    }
    if (90 <= ANGLE_X + world->angle.x && ANGLE_X + world->angle.x < 180) {
        draw_map_quads_3(window, map2d, world);
        return;
    }
    if (0 <= ANGLE_X + world->angle.x && ANGLE_X + world->angle.x < 90)
        draw_map_quads_4(window, map2d, world);
}

void display_map(world_t *world)
{
    create_map(world, 1);
    buttons_world(world);
    draw_2d_map(world->window, world->map, world);
}
