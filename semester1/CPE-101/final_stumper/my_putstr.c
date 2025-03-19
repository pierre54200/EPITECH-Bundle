/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "rush3.h"

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != 0; i++)
        my_putchar(str[i]);
}
