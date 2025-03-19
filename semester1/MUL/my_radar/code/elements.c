/*
** EPITECH PROJECT, 2025
** elements.c
** File description:
** elements
*/
#include "../include/proto.h"

static char *my_revstr(char *str)
{
    int i = 0;
    int stock = 0;
    int stock2 = 0;
    int len = 0;

    while (str[len] != '\0') {
        len = len + 1;
    }
        while (i < len) {
            stock = str[i];
            stock2 = str[len - 1];
            str[len - 1] = stock;
            str[i] = stock2;
            i = i + 1;
            len = len - 1;
        }
    return str;
}

static char *nbr_to_str(int nb, char *stock)
{
    int stock2 = nb;

    for (int i = 0; i != 10; i++)
        stock[i] = 0;
    if (nb == 0)
        stock[0] = '0';
    for (int i = 0; stock2 >= 1; i++) {
        stock[i] = stock2 % 10 + '0';
        stock2 = stock2 / 10;
    }
    my_revstr(stock);
    return stock;
}

sfSprite *create_bg(char *image)
{
    sfVector2f scale = {2.1, 2.1};
    sfSprite *bg = sprite_handler(image);

    sfSprite_setScale(bg, scale);
    return bg;
}

radar_t create_radar_element(radar_t radar)
{
    sfVector2f pos = {10, 800};
    sfVector2f pos1 = {1800, 10};
    char *text = "Enable/Disable :\n\nS sprite\nL hitbox\nC Colision";

    radar.font = sfFont_createFromFile("./src/brotesque/ba.otf");
    radar.bg = create_bg("./src/map.jpg");
    radar.clock = sfClock_create();
    radar.clock_for_click = sfClock_create();
    radar.text = sfText_create();
    sfText_setString(radar.text, text);
    sfText_setColor(radar.text, sfWhite);
    sfText_setPosition(radar.text, pos);
    sfText_setFont(radar.text, radar.font);
    radar.time = sfText_create();
    sfText_setColor(radar.time, sfWhite);
    sfText_setPosition(radar.time, pos1);
    sfText_setFont(radar.time, radar.font);
    return radar;
}

plane_t *create_plane(int *stock, plane_t *plane)
{
    plane_t *new_node = malloc(sizeof(*new_node));
    static int nb_plane = 0;

    if (new_node == NULL)
        return plane;
    new_node->next = plane;
    new_node->nb = nb_plane;
    new_node->start.x = stock[0];
    new_node->start.y = stock[1];
    new_node->end.x = stock[2];
    new_node->end.y = stock[3];
    new_node->speed = stock[4];
    new_node->delay = stock[5];
    new_node->test_x = 0;
    new_node->test_y = 0;
    new_node->rect = create_rect(new_node->start);
    new_node->sprite = plane_handler(new_node);
    plane = new_node;
    nb_plane++;
    return plane;
}

tower_t *create_tower(int *stock, tower_t *tower)
{
    tower_t *new_node = malloc(sizeof(*new_node));
    static int nb_tower = 0;
    sfVector2f pos2;

    if (new_node == NULL)
        return tower;
    new_node->next = tower;
    new_node->nb = nb_tower;
    new_node->pos.x = stock[0];
    new_node->pos.y = stock[1];
    new_node->rad = stock[2];
    pos2.x = new_node->pos.x - stock[2];
    pos2.y = new_node->pos.y - stock[2];
    new_node->circle = create_circle(pos2, new_node->rad);
    new_node->sprite = tower_handler(new_node);
    tower = new_node;
    nb_tower++;
    return tower;
}

radar_t timer(sfRenderWindow *window, radar_t radar)
{
    sfTime time = sfClock_getElapsedTime(radar.clock);
    char timer[10];

    nbr_to_str(time.microseconds / 1000000, timer);
    sfText_setString(radar.time, timer);
    sfRenderWindow_drawText(window, radar.time, NULL);
    return radar;
}
