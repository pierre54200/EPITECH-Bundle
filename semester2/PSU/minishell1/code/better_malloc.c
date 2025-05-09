/*
** EPITECH PROJECT, 2025
** better_malloc.c
** File description:
** better malloc
*/
#include "../include/proto.h"

char *bmalloc(int size)
{
    char *loc = malloc(size);

    if (loc == NULL)
        return NULL;
    for (int i = 0; i != size; i++)
        loc[i] = 0;
    return loc;
}

char **btmalloc(int size)
{
    char **loc = malloc(size);

    if (loc == NULL)
        return NULL;
    for (long unsigned int i = 0; i != size / sizeof(char *); i++)
        loc[i] = 0;
    return loc;
}
