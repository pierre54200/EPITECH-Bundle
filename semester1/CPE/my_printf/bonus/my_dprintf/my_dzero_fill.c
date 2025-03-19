/*
** EPITECH PROJECT, 2024
** my_zero_fill
** File description:
** fill of zero
*/
#include "dproto.h"

int my_dzero_fill(int arg, int nb, int fd)
{
    for (int i = 0; i != nb; i++)
        my_dputchar('0', fd);
    return arg;
}
