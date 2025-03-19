/*
** EPITECH PROJECT, 2024
** duck.h
** File description:
** //
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef DUCK
  #define DUCK
typedef struct sprite_duck {
    sfSprite *name;
    sfVector2f move;
} duck_t;

typedef struct sprite_bg {
    sfSprite *name;
} bg_t;

typedef struct menu {
    sfText *easy;
    sfText *medium;
    sfText *hard;
    sfText *exit;
    sfText *quit;
    sfMusic *music;
    int code;
} menu_t;

typedef struct game {
    duck_t duck;
    bg_t bg;
    menu_t menu;
    sfClock *clock;
    sfSprite *heart;
    sfText *gameover;
    sfSound *pew;
    sfSound *oof;
    sfSprite *pointer;
    sfMusic *music;
    sfSprite *blood;
    sfSprite *flash;
    sfFont *font;
    int score;
    int hp;
    sfSprite *gun;
} game_t;
game_t element(game_t game);
sfSprite *sprite_handler(char *image);
int time_frame(game_t game);
int time_frame_shoot(game_t game);
game_t duck_handler(sfRenderWindow *window, game_t game, int spd);
void my_hunter(game_t game);
game_t background_handler(sfRenderWindow *window, game_t game);
game_t menu(sfRenderWindow *window, game_t game);
char *my_revstr(char *str);
game_t pewpew(game_t game);
sfText *text_handler(char *str, int size, int x, int y);
game_t music(game_t game);
#endif /*DUCK*/
