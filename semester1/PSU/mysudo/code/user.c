/*
** EPITECH PROJECT, 2025
** user.c
** File description:
** find current user
*/

#include "../include/proto.h"

static char *get_name(char *line)
{
    char *name = NULL;
    int len = 0;

    for (; line[len] != ':'; len++);
    name = bmalloc(sizeof(char) * (len + 1));
    if (name == NULL)
        return NULL;
    for (int i = 0; line[i] != ':'; i++)
        name[i] = line[i];
    return name;
}

static char *get_user(char *uid)
{
    char *line = find_in_file("/etc/passwd", uid);

    if (line != NULL)
        if (find_in_string(line, uid) != -1)
            return get_name(line);
    return NULL;
}

char *useri(int uid)
{
    char id[10];

    sprintf(id, "%d", uid);
    return get_user(id);
}
