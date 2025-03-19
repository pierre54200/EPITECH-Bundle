/*
** EPITECH PROJECT, 2024
** sprite_handler.c
** File description:
** sprite
*/
#include "duck.h"

sfSprite *sprite_handler(char *image)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfText *text_handler(char *str, int size, int x, int y)
{
    sfText *text;
    sfVector2f pos;
    game_t game;

    pos.x = x;
    pos.y = y;
    text = sfText_create();
    sfText_setString(text, str);
    game.font = sfFont_createFromFile("./src/m29.TTF");
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setFont(text, game.font);
    return text;
}
