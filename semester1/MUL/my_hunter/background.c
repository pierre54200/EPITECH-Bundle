/*
** EPITECH PROJECT, 2024
** background.c
** File description:
** background.c
*/
#include "duck.h"

game_t background_handler(sfRenderWindow *window, game_t game)
{
    sfRenderWindow_drawSprite(window, game.bg.name, NULL);
    return game;
}
