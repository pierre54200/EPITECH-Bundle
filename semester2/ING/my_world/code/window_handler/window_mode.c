/*
** EPITECH PROJECT, 2025
** window_mode.c
** File description:
** mode
*/

#include "../../include/proto.h"

sfRenderWindow *mode(char *name, int width, int height, int fps)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 32};

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setKeyRepeatEnabled(window, sfTrue);
    return window;
}
