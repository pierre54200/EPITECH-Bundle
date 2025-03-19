/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "duck.h"

static sfRenderWindow *mode(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};

    window = sfRenderWindow_create(video_mode, "Hunter", sfDefaultStyle, NULL);
    return window;
}

static int event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

static game_t gun(sfRenderWindow *window, game_t game)
{
    sfVector2f scale = {0.5, 0.5};
    sfVector2f scale2 = {0.1, 0.1};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {mouse.x, mouse.y};
    sfVector2f pos2 = {mouse.x - 23, mouse.y - 23};

    sfRenderWindow_setMouseCursorVisible(window, 0);
    sfSprite_setScale(game.gun, scale);
    sfSprite_setScale(game.pointer, scale2);
    sfSprite_setPosition(game.gun, pos);
    sfSprite_setPosition(game.pointer, pos2);
    sfRenderWindow_drawSprite(window, game.pointer, NULL);
    if (game.menu.code != 0)
        sfRenderWindow_drawSprite(window, game.gun, NULL);
    return game;
}

static void destroy_everything(game_t game)
{
    sfSprite_destroy(game.blood);
    sfSprite_destroy(game.bg.name);
    sfSprite_destroy(game.duck.name);
    sfSprite_destroy(game.flash);
    sfText_destroy(game.gameover);
    sfSprite_destroy(game.gun);
    sfSprite_destroy(game.heart);
    sfText_destroy(game.menu.easy);
    sfText_destroy(game.menu.medium);
    sfText_destroy(game.menu.hard);
    sfText_destroy(game.menu.exit);
    sfMusic_destroy(game.music);
    sfSound_destroy(game.oof);
    sfSound_destroy(game.pew);
    sfSprite_destroy(game.pointer);
    sfFont_destroy(game.font);
}

void my_hunter(game_t game)
{
    sfRenderWindow *window = mode();

    game.score = 0;
    game.hp = 3;
    sfRenderWindow_setFramerateLimit(window, 60);
    game.clock = sfClock_create();
    game = element(game);
    sfMusic_play(game.menu.music);
    while (sfRenderWindow_isOpen(window)) {
        event(window);
        game = background_handler(window, game);
        game = menu(window, game);
        if (game.menu.code != 0)
            game = duck_handler(window, game, game.menu.code);
        game = gun(window, game);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfColor_fromRGB(0, 0, 0));
    }
    sfRenderWindow_destroy(window);
    destroy_everything(game);
}
