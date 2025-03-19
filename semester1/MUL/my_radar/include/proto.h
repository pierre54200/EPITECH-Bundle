/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** struct for printf
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


#ifndef PROTO_H
    #define PROTO_H
typedef struct radar {
    sfSprite *bg;
    sfClock *clock_for_click;
    sfClock *clock;
    sfText *text;
    sfFont *font;
    sfText *time;
} radar_t;

typedef struct plane {
    sfRectangleShape *rect;
    int nb;
    sfSprite *sprite;
    sfVector2f start;
    sfVector2f end;
    int speed;
    int delay;
    struct plane *next;
    int test_x;
    int test_y;
} plane_t;

typedef struct tower {
    sfCircleShape *circle;
    int nb;
    sfVector2f pos;
    int rad;
    sfSprite *sprite;
    struct tower *next;
} tower_t;

int check_file_exist(char *fp);
plane_t *checka(char *str, int i, plane_t *plane);
tower_t *checkt(char *str, int i, tower_t *tower);
plane_t *create_plane(int *stock, plane_t *plane);
tower_t *create_tower(int *stock, tower_t *tower);
sfRectangleShape *create_rect(sfVector2f position);
sfCircleShape *create_circle(sfVector2f position, float radius);
void display(plane_t *plane, tower_t *tower);
sfSprite *sprite_handler(char *image);
sfSprite *create_bg(char *image);
int kill_everything(plane_t *plane, tower_t *tower, radar_t radar);
sfSprite *plane_handler(plane_t *plane);
sfSprite *tower_handler(tower_t *tower);
plane_t *move(plane_t *plane, tower_t *tower, sfClock *clock, int test);
plane_t *collision(plane_t *plane, tower_t *tower, int test);
radar_t create_radar_element(radar_t radar);
radar_t timer(sfRenderWindow *window, radar_t radar);
#endif /* PROTO_H */
