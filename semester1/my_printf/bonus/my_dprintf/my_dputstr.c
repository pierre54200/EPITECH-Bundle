/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "dproto.h"

int my_dputstr(char const *str, int fd)
{
    int i = 0;

    for (; str[i] != 0; i++)
        my_dputchar(str[i], fd);
    return i;
}

int my_dputstr2(char const *str, char *flag, int fd)
{
    int i = 0;

    for (; str[i] != 0; i++)
        my_dputchar(str[i], fd);
    return i;
}
