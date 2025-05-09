/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** strdup
*/

#include "../include/proto.h"

char **my_tabdup(char **src)
{
    char **dst = malloc(sizeof(char *) * (my_tablen(src) + 1));

    if (dst == NULL)
    return NULL;
    my_tabcpy(dst, src);
    return dst;
}

char *my_strdup(char *src)
{
    char *dst = bmalloc(sizeof(char) * my_strlen(src) + 1);

    if (dst == NULL)
    return NULL;
    my_strcpy(dst, src);
    return dst;
}

char *my_strndup(char *src, int len)
{
    char *dst = bmalloc(sizeof(char) * (my_strlen(src) + 1));

    if (dst == NULL)
    return NULL;
    my_strncpy(dst, src, len);
    return dst;
}

char *my_strntdup(char *src, int len, char to)
{
    char *dst = bmalloc(sizeof(char) * (my_strlen(src) + 1));

    if (dst == NULL)
    return NULL;
    my_strntcpy(dst, src, len, to);
    return dst;
}
