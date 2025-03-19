/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** proto
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

// My_World structure //
typedef struct world_s {
    sfClock *clock;
    sfEvent event;
    sfClock *clock_escape;
    sfClock *clock_water;
    sfRenderWindow *window;
    sfVector2f **map;
    int **map_2d;
    sfVector2f angle;
    float zoom;
    float vertical;
    float horizontal;
    struct menu_s *menu;
    struct option_s *option;
    struct tool_s *tools;
    sfRenderStates **states;
    int mx;
    int my;
    sfSound *dig;
} world_t;

typedef struct menu_s {
    int menu_status;
    sfSprite *world;
    sfSprite *settings;
    sfSprite *exit;
    sfSprite *menu;
} menu_t;

typedef struct option_s {
    sfSprite *sc1;
    sfSprite *sc2;
    sfFont* font;
    sfText* text;
    sfText* int_text_x;
    sfText* int_text_y;
    char input_text[16];
    char input_int_x[3];
    char input_int_y[3];
    int text_len;
    int int_len_x;
    int int_len_y;
    int is_text;
    int is_int_x;
    int is_int_y;
    sfRectangleShape* text_box;
    sfRectangleShape* int_box_x;
    sfRectangleShape* int_box_y;
    sfFloatRect text_bound;
    sfVector2f text_pos;
    float text_width;
    float text_height;
    sfFloatRect int_bound_x;
    sfVector2f int_pos_x;
    float int_width_x;
    float int_height_x;
    sfFloatRect int_bound_y;
    sfVector2f int_pos_y;
    float int_width_y;
    float int_height_y;
} option_t;

typedef struct tool_s {
    int color_id;
    sfSprite *help_red;
    sfSprite *help_green;
    sfSprite *help_blue;
    sfSprite *help_yellow;
    sfSprite *help_point;
    sfSprite *help_square;
    sfColor color;
    sfColor cursor;
    sfSprite *blue;
    sfSprite *red;
    sfSprite *yellow;
    sfSprite *green;
    sfSprite *square;
    sfSprite *point;
    int current_tool;
    int symetric;
} tool_t;

// Enum for menu //
enum MENU {
    MENU,
    WORLD,
    OPTIONS
};

enum COLOR {
    GREEN,
    RED,
    BLUE,
    YELLOW,
    POINT,
    SQUARE
};

#ifndef PROTO_H
    #define PROTO_H
    #define MX world->mx
    #define MY world->my
    #define ANGLE_X 135
    #define ANGLE_Y 0.3
    #define SIZE 20.0
    #define PI 3.1415
    #define XSIZE 800
    #define YSIZE 600
    #define DEFAULT_ALT 5
    #define MAX_TEXT_LENGTH 15
    #define MAX_INT_LENGTH 2
    #define FONT "./src/arial.ttf"
    #define PERM 0666
    #define DIG "./src/dig.mp3"

extern const char *tile_textures[4];
extern const char *help_boxes[6];
extern const char *menu[4];
extern const char *tools[6];
extern const char *shortcut[2];

// World //
int my_world(void);
void reset(world_t *world);

// Window handler //
int event(world_t *world);
sfRenderWindow *mode(char *name, int width, int height, int fps);
int timer_for_key_pressed(sfClock *clock, int timer);

// Elem //
sfText *text_handler(char *str, int size, int x, int y);
sfSprite *sprite_handler(const char *image, sfVector2f pos, sfVector2f scale);
void create_map(world_t *world, int test);
void create_menu(world_t *world);
void create_tools(world_t *world);
void create_option(world_t *world);
void create_bound(world_t *world);
void tool_box_tools(world_t *w, int nb);
void tool_box(world_t *w, int nb);
void create_helpbox(world_t *world);
void create_sound(world_t *world);

// Elem handler //
void set_my_world(world_t *world);
void set_clock(world_t *world);
int timer(sfClock *clock, int timer);

// Displayer //
void display(world_t *world);
void display_menu(world_t *world);
void display_options(world_t *world);
void display_world(world_t *world);
void display_map(world_t *world);
void check_click1(world_t *world, int y, int x, sfVector2f point[4]);
void check_click2(world_t *world, int y, int x, sfVector2f point[4]);
void check_click3(world_t *world, int y, int x, sfVector2f point[4]);
void check_click4(world_t *world, int y, int x, sfVector2f point[4]);

// Free Element //
void free_world(world_t *world);

// Buttons //
sfSprite *exit_handler(world_t *world, sfSprite *button);
sfSprite *world_handler(world_t *world, sfSprite *button);
sfSprite *settings_handler(world_t *world, sfSprite *button);
sfSprite *menu_handler(world_t *world, sfSprite *button);
void buttons_menu(world_t *world);
void buttons_world(world_t *world);

// Save_map //
int save_map(world_t *world);
void load_map(world_t *world);
void recreate_map(world_t *world);

#endif /* PROTO_H */
