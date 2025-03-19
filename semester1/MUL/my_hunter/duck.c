/*
** EPITECH PROJECT, 2024
** duck.c
** File description:
** duck.c
*/
#include "duck.h"

static sfSprite *sprite_rec(sfSprite *sprite, int time)
{
    sfIntRect rec;

    rec.height = 110;
    rec.width = 110;
    rec.left = 110 * time;
    rec.top = 0;
    sfSprite_setTextureRect(sprite, rec);
    return sprite;
}

static game_t move_duck(game_t game, int spd)
{
    sfVector2f pos;

    if (game.menu.code == -1)
        return game;
    game.duck.move.x = spd * 5;
    game.duck.move.y = (rand() % 2 + 1) * (-1) * (rand() % 2);
    pos.x = -110;
    pos.y = rand() % 4500 / 10;
    sfSprite_move(game.duck.name, game.duck.move);
    if (sfSprite_getPosition(game.duck.name).x > 800) {
        sfSound_play(game.oof);
        game.hp = game.hp - 1;
        sfSprite_setPosition(game.duck.name, pos);
    }
    return game;
}

static char *get_score(game_t game, char *stock)
{
    int stock2 = game.score;

    for (int i = 0; i != 10; i++)
        stock[i] = 0;
    if (game.score == 0)
        stock[0] = '0';
    for (int i = 0; stock2 >= 1; i++) {
        stock[i] = stock2 % 10 + '0';
        stock2 = stock2 / 10;
    }
    my_revstr(stock);
    return stock;
}

static int score(sfRenderWindow *window, game_t game)
{
    sfText *score;
    sfVector2f pos = {10, 10};
    sfFont *font;
    char stock[10];

    get_score(game, stock);
    score = sfText_create();
    sfText_setString(score, stock);
    font = sfFont_createFromFile("./src/m29.TTF");
    sfText_setCharacterSize(score, 34);
    sfText_setPosition(score, pos);
    sfText_setFont(score, font);
    sfRenderWindow_drawText(window, score, NULL);
    return 0;
}

game_t duck_hitbox2(game_t game, sfRenderWindow *window, sfVector2f pos)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f duck_place = sfSprite_getPosition(game.duck.name);
    sfVector2f pos2 = {mouse.x - 50, mouse.y - 50};
    sfVector2f pos3 = {mouse.x - 150, mouse.y - 70};

    if (mouse.x > duck_place.x && mouse.x < duck_place.x + 110
    && mouse.y > duck_place.y && mouse.y < duck_place.y + 110
    && sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        sfClock_restart(game.clock);
        sfSprite_setPosition(game.blood, pos2);
        sfSprite_setPosition(game.flash, pos3);
        sfRenderWindow_drawSprite(window, game.blood, NULL);
        sfRenderWindow_drawSprite(window, game.flash, NULL);
        sfSound_play(game.pew);
        game.score = game.score + 10;
        sfSprite_setPosition(game.duck.name, pos);
    }
    return game;
}

game_t duck_hitbox(game_t game, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos;
    sfVector2f pos3 = {mouse.x - 150, mouse.y - 70};

    pos.x = -110;
    pos.y = rand() % 4500 / 10;
    game = duck_hitbox2(game, window, pos);
    if (time_frame_shoot(game) == 0) {
        sfSprite_setPosition(game.flash, pos3);
        sfRenderWindow_drawSprite(window, game.blood, NULL);
        sfRenderWindow_drawSprite(window, game.flash, NULL);
    }
    return game;
}

game_t quit(sfRenderWindow *window, game_t game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && mouse.x > 340
        && mouse.x < 500 && mouse.y > 300 && mouse.y < 325) {
        game.menu.code = 0;
        game.score = 0;
        sfClock_restart(game.clock);
        game.hp = 3;
        sfMusic_play(game.menu.music);
    }
    return game;
}

static game_t gameover(sfRenderWindow *window, game_t game)
{
    sfVector2f pos3 = {800, 600};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (game.hp <= 0) {
        sfSprite_setPosition(game.heart, pos3);
        sfRenderWindow_drawSprite(window, game.heart, NULL);
        sfRenderWindow_drawText(window, game.gameover, NULL);
        if (mouse.x > 340 && mouse.x < 500
        && mouse.y > 300 && mouse.y < 350)
            sfRenderWindow_drawText(window, game.menu.quit, NULL);
        game.menu.code = -1;
        game = quit(window, game);
    }
    return game;
}

static game_t life(sfRenderWindow *window, game_t game)
{
    sfVector2f pos = {0, 550};
    sfVector2f pos1 = {50, 550};
    sfVector2f pos2 = {100, 550};

    if (game.hp == 3) {
        sfSprite_setPosition(game.heart, pos);
        sfRenderWindow_drawSprite(window, game.heart, NULL);
    }
    if (game.hp >= 2) {
        sfSprite_setPosition(game.heart, pos1);
        sfRenderWindow_drawSprite(window, game.heart, NULL);
    }
    if (game.hp >= 1) {
        sfSprite_setPosition(game.heart, pos2);
        sfRenderWindow_drawSprite(window, game.heart, NULL);
    }
    game = gameover(window, game);
    return game;
}

game_t duck_handler(sfRenderWindow *window, game_t game, int spd)
{
    game.duck.name = sprite_rec(game.duck.name, time_frame(game));
    game = move_duck(game, spd);
    game = duck_hitbox(game, window);
    sfRenderWindow_drawSprite(window, game.duck.name, NULL);
    score(window, game);
    game = life(window, game);
    return game;
}
