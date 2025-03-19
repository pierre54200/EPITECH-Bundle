/*
** EPITECH PROJECT, 2024
** element.c
** File description:
** element.c
*/
#include "duck.h"

static game_t create_duck(game_t game, int x, int y)
{
    game.duck.name = sprite_handler("./src/duck.png");
    game.duck.move.x = x;
    game.duck.move.y = y;
    return game;
}

static game_t create_background(game_t game)
{
    game.bg.name = sprite_handler("./src/game_bg.png");
    return game;
}

static game_t create_menu(game_t game)
{
    game.menu.easy = text_handler("easy", 42, 340, 100);
    game.menu.medium = text_handler("medium", 42, 300, 200);
    game.menu.hard = text_handler("hard", 42, 340, 300);
    game.menu.exit = text_handler("exit", 42, 345, 400);
    return game;
}

static game_t create_heart(game_t game)
{
    sfVector2f pos = {650, 550};

    game.heart = sprite_handler("./src/heart.png");
    sfSprite_setPosition(game.heart, pos);
    return game;
}

static game_t create_gameover(game_t game)
{
    game.gameover = text_handler("gameover", 54, 200, 200);
    game.menu.quit = text_handler("quit", 42, 340, 300);
    return game;
}

static game_t spas12(game_t game)
{
    game.pointer = sprite_handler("./src/pointer.png");
    game.gun = sprite_handler("./src/spas12.png");
    return game;
}

static game_t blood(game_t game)
{
    sfVector2f scale = {5, 5};
    sfVector2f scale2 = {10, 10};

    game.blood = sprite_handler("./src/blood.png");
    sfSprite_setScale(game.blood, scale);
    game.flash = sprite_handler("./src/flash.png");
    sfSprite_setScale(game.flash, scale2);
    return game;
}

game_t element(game_t game)
{
    game = create_menu(game);
    game = create_duck(game, -110, 0);
    game = create_background(game);
    game = create_heart(game);
    game = create_gameover(game);
    game = pewpew(game);
    game = spas12(game);
    game = music(game);
    game = blood(game);
    return game;
}
