/*
** EPITECH PROJECT, 2025
** save_map.c
** File description:
** save_map
*/

#include "../../include/proto.h"
#include <fcntl.h>
#include <unistd.h>

static int save_map_w_name(world_t *world)
{
    char buffer[30];
    int fd;
    int nbr = 0;
    int a = 0;

    sprintf(buffer, "%s%s", world->option->input_text, ".legend");
    fd = open(buffer, O_WRONLY | O_CREAT, PERM);
    if (fd < 0)
    return 84;
    for (int i = 0; i != MY; i++) {
        for (int j = 0; j != MX; j++) {
            nbr = world->map_2d[i][j] + '0';
            a = write(fd, &nbr, 1);
            a = write(fd, " ", 1);
        }
        a = write(fd, "\n", 1);
    }
    a = a;
    close(fd);
    return 0;
}

static int save_map_wo_name(world_t *world)
{
    int fd = open("./save.legend", O_WRONLY | O_CREAT, PERM);
    int nbr = 0;
    int a = 0;

    if (fd < 0)
        return 84;
    for (int i = 0; i != MY; i++) {
        for (int j = 0; j != MX; j++) {
            nbr = world->map_2d[i][j] + '0';
            a = write(fd, &nbr, 1);
            a = write(fd, " ", 1);
        }
        a = write(fd, "\n", 1);
    }
    a = a;
    close(fd);
    return 0;
}

int save_map(world_t *world)
{
    if (world->option->input_text[0] == 0)
        return save_map_wo_name(world);
    return save_map_w_name(world);
}
