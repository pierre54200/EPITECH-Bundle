/*
** EPITECH PROJECT, 2024
** my_display_sign
** File description:
** add a sign
*/
#include "dproto.h"

int my_ddisplay_sign(int i, int nb, int fd)
{
    if (nb >= 0){
        my_dputchar('+', fd);
        return 1;
    }
    return 0;
}
