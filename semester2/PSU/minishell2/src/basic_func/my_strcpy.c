/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copy a string
*/
#include "proto.h"

char **my_tabcpy(char **dest, char **src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = my_strdup(src[i]);
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char *src, int len)
{
    int i = 0;

    while (src[len] != '\0') {
        dest[i] = src[len];
        i = i + 1;
        len++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strntcpy(char *dest, char *src, int len, char to)
{
    int i = 0;

    while (src[len] != '\0' && src[len] != to) {
        dest[i] = src[len];
        i = i + 1;
        len++;
    }
    dest[i] = '\0';
    return dest;
}
