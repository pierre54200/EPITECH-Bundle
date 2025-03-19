/*
** EPITECH PROJECT, 2024
** my_zero_fill
** File description:
** fill of zero
*/
#include "fproto.h"

int my_fzero_fill(int arg, int nb, int fd)
{
    for (int i = 0; i != nb; i++)
        my_fputchar('0', fd);
    return arg;
}
