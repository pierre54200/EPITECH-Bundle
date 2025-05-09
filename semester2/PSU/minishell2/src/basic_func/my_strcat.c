/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/

#include "proto.h"

char *my_strcot(char *dest, char *src)
{
    int max = my_strlen(dest) + my_strlen(src);
    char *result = malloc(max + 1);
    int i = 0;
    int j = 0;

    if (result == NULL)
        return NULL;
    for (; dest[j] != '\0'; j++)
        result[j] = dest[j];
    for (; src[i] != '\0'; i++)
        result[j + i] = src[i];
    result[j + i] = '\0';
    return result;
}

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;

    for (; dest[len] != '\0'; len++);
    for (; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = 0;
    return dest;
}
