/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** print char per char
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putchar2(va_list list, int nbvir, char *flag)
{
    int c = va_arg(list, int);

    my_putchar(c);
    return 1;
}
