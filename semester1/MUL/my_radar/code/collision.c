/*
** EPITECH PROJECT, 2025
** collision.c
** File description:
** collision
*/

#include "../include/proto.h"

int ctower(plane_t *plane, tower_t *t)
{
    sfVector2f pos = sfSprite_getPosition(plane->sprite);
    int test = 0;

    while (t != NULL) {
        test = pow(20 + t->rad, 2);
        if (pow(pos.x - t->pos.x, 2) + (pow(pos.y - t->pos.y, 2)) <= test)
            return 1;
        t = t->next;
    }
    return 0;
}

plane_t *collision_plane(plane_t *plane, tower_t *tower)
{
    plane_t *plane1 = plane;
    sfVector2f pos = sfSprite_getPosition(plane->sprite);
    sfVector2f pos1;
    sfVector2f pos2 = {-40, -40};

    while (plane1 != NULL) {
        pos1 = sfSprite_getPosition(plane1->sprite);
        if (((pos.x - pos1.x <= 20 && pos.x - pos1.x >= -20)
        && (pos.y - pos1.y <= 20 && pos.y - pos1.y >= -20))
        && plane->nb != plane1->nb && ctower(plane, tower) == 0) {
            sfSprite_setPosition(plane1->sprite, pos2);
            sfRectangleShape_setPosition(plane1->rect, pos2);
            sfSprite_setPosition(plane->sprite, pos2);
            sfRectangleShape_setPosition(plane->rect, pos2);
            return plane;
        }
        plane1 = plane1->next;
    }
    return plane;
}

plane_t *collision(plane_t *plane, tower_t *tower, int test)
{
    plane_t *plane1 = plane;

    if (test < 10)
        while (plane1 != NULL) {
            plane1 = collision_plane(plane1, tower);
            plane1 = plane1->next;
        }
    return plane;
}
