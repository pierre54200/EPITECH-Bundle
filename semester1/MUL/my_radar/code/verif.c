/*
** EPITECH PROJECT, 2025
** verif.c
** File description:
** verif
*/
#include "../include/proto.h"

static int size_buffer(char *fp)
{
    struct stat s;

    if (stat(fp, &s) < 0)
        return -1;
    return s.st_size;
}

static char *clear_str(char *str, int len)
{
    for (int i = len; i >= 0; i--)
        str[i] = 0;
    return str;
}

static int check_til_line(char *str, int i)
{
    for (; str[i] != '\n' && str[i] != 0; i++);
    return i;
}

static int check_file_is_radar(char *str, plane_t *plane, tower_t *tower)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != 'A' && str[i] != 'T')
            return 84;
        if (str[i] == 'A') {
            plane = checka(str, i + 1, plane);
            i = check_til_line(str, i);
        }
        if (str[i] == 'T') {
            tower = checkt(str, i + 1, tower);
            i = check_til_line(str, i);
        }
    }
    display(plane, tower);
    return 0;
}

static int check_file_correct(int fd, char *fp)
{
    int size = size_buffer(fp);
    char buffer[size];
    int entry;
    plane_t *plane = NULL;
    tower_t *tower = NULL;

    clear_str(buffer, size + 1);
    entry = read(fd, buffer, size);
    if (size < 0)
        return 84;
    if (entry < 0)
        return 84;
    close(fd);
    return check_file_is_radar(buffer, plane, tower);
}

int check_file_exist(char *fp)
{
    int fd = open(fp, O_RDONLY);

    if (fd == -1)
        return 84;
    return check_file_correct(fd, fp);
}
