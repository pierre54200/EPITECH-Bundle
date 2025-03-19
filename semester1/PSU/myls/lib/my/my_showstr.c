/*
** EPITECH PROJECT, 2024
** my_showstr
** File description:
** showstr
*/
#include "my.h"

static void hex(char c)
{
    my_putchar('/');
    if (c < 16)
        my_putchar('0');
    if (c >= 16)
        my_putchar('1');
    if (c % 16 >= 10)
        my_putchar(c % 16 - 10 + 'a');
    if (c % 16 < 10)
        my_putchar(c % 16 + '0');
    return;
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32)
            hex(str[i]);
        else
            my_putchar(str[i]);
    }
    return 0;
}
