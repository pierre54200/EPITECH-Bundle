/*
** EPITECH PROJECT, 2025
** clear.c
** File description:
** clear data
*/

#include "../include/proto.h"

int kill_everything_radar(radar_t radar)
{
    sfSprite_destroy(radar.bg);
    sfClock_destroy(radar.clock_for_click);
    sfClock_destroy(radar.clock);
    return 0;
}

int kill_everything(plane_t *plane, tower_t *tower, radar_t radar)
{
    tower_t *tower2;
    plane_t *plane2;

    while (tower != NULL) {
        tower2 = tower;
        sfCircleShape_destroy(tower->circle);
        sfSprite_destroy(tower->sprite);
        tower = tower->next;
        free(tower2);
    }
    while (plane != NULL) {
        plane2 = plane;
        sfRectangleShape_destroy(plane->rect);
        sfSprite_destroy(plane->sprite);
        plane = plane->next;
        free(plane2);
    }
    kill_everything_radar(radar);
    return 0;
}
