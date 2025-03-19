/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** task01
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    for (; src[i] != '\0'; i++);
    str = malloc(sizeof(char) * (i + 1));
    my_strcpy(str, src);
    return str;
}
