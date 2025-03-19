/*
** EPITECH PROJECT, 2025
** sprite_handler.c
** File description:
** handle sprite
*/

#include "../include/proto.h"

sfSprite *sprite_handler(char *image)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *plane_handler(plane_t *plane)
{
    sfSprite *sprite = sprite_handler("./src/plane.png");
    sfVector2f size = {0.1, 0.1};
    sfVector2f pos = {plane->start.x - 5, plane->start.y - 5};

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return sprite;
}

sfSprite *tower_handler(tower_t *t)
{
    sfSprite *sprite = sprite_handler("./src/tower.png");
    sfVector2f size = {0.1, 0.1};
    sfVector2f pos = {t->pos.x - 25, t->pos.y - 25};

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return sprite;
}
