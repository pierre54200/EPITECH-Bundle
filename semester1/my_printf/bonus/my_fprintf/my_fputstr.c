/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "fproto.h"

int my_fputstr(char const *str, int fd)
{
    int i = 0;

    for (; str[i] != 0; i++)
        my_fputchar(str[i], fd);
    return i;
}

int my_fputstr2(char const *str, char *flag, int fd)
{
    int i = 0;

    for (; str[i] != 0; i++)
        my_fputchar(str[i], fd);
    return i;
}
