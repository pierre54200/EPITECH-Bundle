/*
** EPITECH PROJECT, 2025
** load_map.c
** File description:
** load the map
*/

#include "../../include/proto.h"
#include <fcntl.h>

static int nbr_of_space(char *str)
{
    int i = 0;
    int nb = 0;

    for (; str[i] != 0; i++) {
        if (str[i] == ' ')
            nb++;
    }
    return nb - 1;
}

static int *my_get_nb_line(char *line, int *mat)
{
    int j = 0;

    mat[0] = 0;
    for (int i = 0; line[i + 2] != 0; i++) {
        if (line[i] == ' ') {
            j++;
            mat[j] = 0;
        } else
            mat[j] = mat[j] * 10 + line[i] - '0';
    }
    return mat;
}

static void recreate_load_map(char *buffer, world_t *world, int my, int mx)
{
    FILE *file = fopen(buffer, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    int **map = malloc(sizeof(int *) * my);

    if (map == NULL)
        return;
    for (int i = 0; i != my; i++)
        map[i] = malloc(sizeof(int) * mx + 1);
    for (int i = 0; i != my; i++) {
        nread = getline(&line, &len, file);
        map[i] = my_get_nb_line(line, map[i]);
    }
    nread = nread;
    world->mx = mx;
    world->my = my;
    world->map_2d = map;
    fclose(file);
    free(line);
}

void load_map(world_t *world)
{
    FILE *file;
    char buffer[30];
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    int h = -1;

    world->option->input_int_x[0] = 0;
    world->option->input_int_y[0] = 0;
    if (world->option->input_text[0] == 0)
        return;
    sprintf(buffer, "%s%s", world->option->input_text, ".legend");
    file = fopen(buffer, "r");
    if (file == NULL)
        return;
    for (; nread != -1; h++) {
        nread = getline(&line, &len, file);
    }
    fclose(file);
    recreate_load_map(buffer, world, h, nbr_of_space(line));
}
