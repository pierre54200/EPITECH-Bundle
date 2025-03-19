/*
** EPITECH PROJECT, 2025
** sprite_handler.c
** File description:
** handle
*/

#include "../../include/proto.h"

sfSprite *sprite_handler(const char *image, sfVector2f pos, sfVector2f scale)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfFloatRect box;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    box = sfSprite_getLocalBounds(sprite);
    pos.x -= box.width / 2;
    pos.y -= box.height / 2;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
