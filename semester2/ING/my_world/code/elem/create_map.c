/*
** EPITECH PROJECT, 2025
** create_map.c
** File description:
** create map
*/

#include "../../include/proto.h"

static sfVector2f project_iso_point(world_t *world, int x, int y, int z)
{
    double angle_x = (ANGLE_X + world->angle.x);
    double angle_y = (ANGLE_Y + world->angle.y);
    double r_angle_x = angle_x * (PI / 180);
    double r_angle_y = r_angle_x + (-90 * (PI / 180));
    double center = (float)(MX - 1) / 2.0;
    sfVector2f array_point;

    array_point.x = cos(r_angle_x) * (x - center) +
    cos(r_angle_y) * (y - center);
    array_point.y = sin(r_angle_x) * (x - center) +
    sin(r_angle_y) * (y - center);
    array_point.x = (array_point.x * (SIZE + world->zoom));
    array_point.y *= angle_y;
    array_point.y -= z - DEFAULT_ALT;
    array_point.x += world->horizontal;
    array_point.y += world->vertical;
    array_point.y = (array_point.y * (SIZE + world->zoom));
    return array_point;
}

static sfVector2f **create_2d_map(int **map, world_t *world)
{
    sfVector2f **map2d = malloc(sizeof(sfVector2f *) * MY);

    for (int i = 0; i < MY; i++)
        map2d[i] = malloc(sizeof(sfVector2f) * MX);
    for (int y = 0; y < MY; y++) {
        for (int x = 0; x < MX; x++) {
            map2d[y][x] = project_iso_point(world, x, y, map[y][x]);
            map2d[y][x].x += XSIZE / 2;
            map2d[y][x].y += YSIZE / 4;
        }
    }
    return map2d;
}

static void set_map(world_t *world)
{
    int **map = malloc(sizeof(int *) * MY);

    if (map == NULL)
    return;
    for (int i = 0; i != MY; i++) {
        map[i] = malloc(sizeof(int) * MX);
        if (map[i] == NULL)
            return;
    }
    for (int y = 0; y < MY; y++) {
        for (int x = 0; x < MX; x++)
            map[y][x] = 0;
    }
    world->map_2d = map;
    world->map = create_2d_map(map, world);
}

void create_map(world_t *world, int test)
{
    if (test == 0)
    set_map(world);
    else
        world->map = create_2d_map(world->map_2d, world);
}
