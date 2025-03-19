/*
** EPITECH PROJECT, 2025
** display.c
** File description:
** display
*/

#include "../include/proto.h"

static sfRenderWindow *mode(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "Radar", sfDefaultStyle, NULL);
    return window;
}

int event(sfRenderWindow *window, plane_t *plane, tower_t *tower, radar_t r)
{
    sfEvent event;
    int test = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyQ) == 1 || test != 0) {
            kill_everything(plane, tower, r);
            sfRenderWindow_close(window);
        }
    }
    return 0;
}

void display_plane(plane_t *plane, sfRenderWindow *window, int test)
{
    while (plane != NULL) {
        if (test == 0 || test == 1 || test == 10 || test == 11)
            sfRenderWindow_drawRectangleShape(window, plane->rect, NULL);
        if (test == 0 || test == 2 || test == 10 || test == 12)
            sfRenderWindow_drawSprite(window, plane->sprite, NULL);
        plane = plane->next;
    }
}

void display_tower(tower_t *tower, sfRenderWindow *window, int test)
{
    while (tower != NULL) {
        if (test == 0 || test == 1 || test == 10 || test == 11)
            sfRenderWindow_drawCircleShape(window, tower->circle, NULL);
        if (test == 0 || test == 2 || test == 10 || test == 12)
            sfRenderWindow_drawSprite(window, tower->sprite, NULL);
        tower = tower->next;
    }
}

static int button_pressc(int test, sfTime time, sfClock *clock)
{
    if ((test == 10 || test == 11 || test == 12 || test == 13)
    && sfKeyboard_isKeyPressed(sfKeyC) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test - 10;
    }
    if ((test == 0 || test == 1 || test == 2 || test == 3)
    && sfKeyboard_isKeyPressed(sfKeyC) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test + 10;
    }
    return test;
}

static int button_pressl(int test, sfTime time, sfClock *clock)
{
    if ((test == 0 || test == 1 || test == 10 || test == 11)
    && sfKeyboard_isKeyPressed(sfKeyL) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test + 2;
    }
    if ((test == 2 || test == 3 || test == 12 || test == 13)
    && sfKeyboard_isKeyPressed(sfKeyL) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test - 2;
    }
    test = button_pressc(test, time, clock);
    return test;
}

static int button_press(int test, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if ((test == 0 || test == 2 || test == 10 || test == 12)
    && sfKeyboard_isKeyPressed(sfKeyS) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test + 1;
    }
    if ((test == 1 || test == 3 || test == 11 || test == 13)
    && sfKeyboard_isKeyPressed(sfKeyS) == 1 && time.microseconds > 200000) {
        sfClock_restart(clock);
        return test - 1;
    }
    test = button_pressl(test, time, clock);
    return test;
}

void display(plane_t *plane, tower_t *tower)
{
    radar_t radar = create_radar_element(radar);
    sfRenderWindow *window = mode();
    int test = 0;

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        plane = move(plane, tower, radar.clock, test);
        sfRenderWindow_drawSprite(window, radar.bg, NULL);
        display_plane(plane, window, test);
        display_tower(tower, window, test);
        test = button_press(test, radar.clock_for_click);
        event(window, plane, tower, radar);
        sfRenderWindow_drawText(window, radar.text, NULL);
        timer(window, radar);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfColor_fromRGB(0, 0, 0));
    }
    sfRenderWindow_destroy(window);
}
