/*
** EPITECH PROJECT, 2024
** my_display_sign
** File description:
** add a sign
*/
#include "fproto.h"

int my_fspace(int arg, int nb, int fd)
{
    if (nb >= 0){
        my_fputchar(' ', fd);
        return 1;
    }
    return 0;
}
