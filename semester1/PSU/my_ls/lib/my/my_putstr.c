/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "proto.h"
#include <stdarg.h>
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    write(1, str, my_strlen(str));
    return i;
}

int my_putstr2(va_list list, int nbvir, char *flag)
{
    int i = 0;
    char *str = va_arg(list, char *);

    for (; str[i] != 0; i++)
        my_putchar(str[i]);
    return i;
}
