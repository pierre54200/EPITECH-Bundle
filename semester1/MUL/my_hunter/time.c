/*
** EPITECH PROJECT, 2024
** time.c
** File description:
** time
*/

#include "duck.h"

int time_frame_shoot(game_t game)
{
    sfTime time;

    time = sfClock_getElapsedTime(game.clock);
    if (time.microseconds < 150000)
        return 0;
    return 1;
}

int time_frame(game_t game)
{
    sfTime time;

    time = sfClock_getElapsedTime(game.clock);
    if (time.microseconds % 300000 < 100000)
        return 0;
    if (time.microseconds % 300000 < 200000)
        return 1;
    if (time.microseconds % 300000 < 300000)
        return 2;
    return 0;
}
