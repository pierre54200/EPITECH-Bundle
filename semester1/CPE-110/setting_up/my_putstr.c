/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr
*/
#include <unistd.h>
#include "setting.h"

int my_putstr(const char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}
