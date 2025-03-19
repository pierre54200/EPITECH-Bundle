/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** count len of a str
*/

#include "../proto.h"

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}
