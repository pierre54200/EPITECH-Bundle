/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** print a str
*/

#include "../proto.h"

int my_putstr(const char *str)
{
    int i = my_strlen(str);

    i = write(1, str, i);
    return i;
}

int my_puts(const char *str)
{
    int i = my_strlen(str);

    i = write(2, str, i);
    return i;
}

int my_putchar(char c)
{
    return write(1, &c, 1);
}
