/*
** EPITECH PROJECT, 2025
** reset.c
** File description:
** reset
*/

#include "../../include/proto.h"

void reset(world_t *world)
{
    for (int i = 0; i != MY; i++) {
        for (int j = 0; j != MX; j++)
            world->map_2d[i][j] = 0;
    }
}
