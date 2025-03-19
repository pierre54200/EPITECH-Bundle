/*
** EPITECH PROJECT, 2025
** set_clock.c
** File description:
** set clock
*/

#include "../../include/proto.h"

int timer(sfClock *clock, int timer)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (time.microseconds % timer >= timer / 2)
        return 1;
    return 0;
}

void set_clock(world_t *world)
{
    world->clock = sfClock_create();
    world->clock_escape = sfClock_create();
    world->clock_water = sfClock_create();
}
