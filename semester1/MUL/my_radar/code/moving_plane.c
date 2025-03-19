/*
** EPITECH PROJECT, 2025
** moving_plane.c
** File description:
** move plane
*/

#include "../include/proto.h"

plane_t *moving(plane_t *p, sfVector2f mov, sfClock *clock)
{
    double dis;
    sfTime time = sfClock_getElapsedTime(clock);

    if (p->delay <= time.microseconds / 1000000 &&
    (p->test_x != 1 || p->test_y != 1)) {
        dis = sqrt(pow((p->end.x - p->start.x), 2)
        + pow((p->end.y - p->start.y), 2));
        mov.x = (p->end.x - p->start.x) / dis * p->speed / 2;
        mov.y = (p->end.y - p->start.y) / dis * p->speed / 2;
        sfSprite_move(p->sprite, mov);
        sfRectangleShape_move(p->rect, mov);
    }
    return p;
}

plane_t *move(plane_t *plane, tower_t *tower, sfClock *clock, int test)
{
    sfVector2f mov;
    plane_t *p = plane;
    sfVector2f pos;

    while (p != NULL) {
        pos = sfSprite_getPosition(p->sprite);
        if ((pos.x >= p->end.x && p->end.x >= p->start.x)
        || (pos.x <= p->end.x && p->end.x <= p->start.x))
            p->test_x = 1;
        if ((pos.y >= p->end.y && p->end.y >= p->start.y)
        || (pos.y <= p->end.y && p->end.y <= p->start.y))
            p->test_y = 1;
        p = moving(p, mov, clock);
        p = p->next;
    }
    plane = collision(plane, tower, test);
    return plane;
}
