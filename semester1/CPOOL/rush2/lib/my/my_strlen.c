/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** task03
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; (str[i] != '\0'); i++);
    return i;
}
