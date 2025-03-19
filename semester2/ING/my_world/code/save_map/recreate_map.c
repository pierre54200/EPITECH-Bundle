/*
** EPITECH PROJECT, 2025
** recreate_map.c
** File description:
** recreate map
*/

#include "../../include/proto.h"

void recreate_map(world_t *world)
{
    if ((world->mx != atoi(world->option->input_int_x)
    || world->my != atoi(world->option->input_int_y))
    && world->option->input_int_x[0] != 0
    && world->option->input_int_y[0] != 0
    && atoi(world->option->input_int_y) > 0
    && atoi(world->option->input_int_x) > 0) {
        free(world->map_2d);
        world->mx = atoi(world->option->input_int_x);
        world->my = atoi(world->option->input_int_y);
        create_map(world, 0);
        }
}
