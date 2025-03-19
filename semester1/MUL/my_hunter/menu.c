/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** menu
*/
#include "duck.h"

void display_menu(sfRenderWindow *window, game_t game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if ((mouse.x < 340 || mouse.x > 500)
        || (mouse.y < 100 || mouse.y > 150))
        sfRenderWindow_drawText(window, game.menu.easy, NULL);
    if ((mouse.x < 300 || mouse.x > 555)
        || (mouse.y < 200 || mouse.y > 250))
        sfRenderWindow_drawText(window, game.menu.medium, NULL);
    if ((mouse.x < 340 || mouse.x > 500)
        || (mouse.y < 300 || mouse.y > 350))
        sfRenderWindow_drawText(window, game.menu.hard, NULL);
    if ((mouse.x < 345 || mouse.x > 500)
        || (mouse.y < 400 || mouse.y > 450))
        sfRenderWindow_drawText(window, game.menu.exit, NULL);
    return;
}

static int time_btw_click(game_t game)
{
    sfTime time;

    time = sfClock_getElapsedTime(game.clock);
    if (time.microseconds < 120000)
        return 1;
    return 0;
}

game_t menu2(sfRenderWindow *window, game_t game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && mouse.x > 340
        && mouse.x < 500 && mouse.y > 300 && mouse.y < 325
        && time_btw_click(game) == 0) {
        game.menu.code = 3;
        sfMusic_pause(game.menu.music);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && mouse.x > 340
        && mouse.x < 500 && mouse.y > 400 && mouse.y < 425) {
        exit(0);
    }
    return game;
}

game_t menu(sfRenderWindow *window, game_t game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (game.menu.code != 0)
        return game;
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && mouse.x > 340
        && mouse.x < 500 && mouse.y > 100 && mouse.y < 125) {
        game.menu.code = 1;
        sfMusic_pause(game.menu.music);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1 && mouse.x > 300
        && mouse.x < 500 && mouse.y > 200 && mouse.y < 225) {
        game.menu.code = 2;
        sfMusic_pause(game.menu.music);
    }
    game = menu2(window, game);
    display_menu(window, game);
    return game;
}
