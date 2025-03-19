/*
** EPITECH PROJECT, 2024
** sound.c
** File description:
** sound
*/
#include "duck.h"

game_t pewpew(game_t game)
{
    game.pew = sfSound_create();
    game.oof = sfSound_create();
    sfSound_setBuffer(game.pew, sfSoundBuffer_createFromFile("./src/pew.mp3"));
    sfSound_setBuffer(game.oof, sfSoundBuffer_createFromFile("./src/oof.mp3"));
    return game;
}

game_t music(game_t game)
{
    game.menu.music = sfMusic_createFromFile("./src/menu_music.wav");
    sfMusic_setLoop(game.menu.music, 1);
    sfMusic_setVolume(game.menu.music, 100);
    return game;
}
