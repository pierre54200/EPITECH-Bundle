/*
** EPITECH PROJECT, 2024
** is_a_char
** File description:
** .c
*/
#include "../include/proto.h"

int is_a_char(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    if (a >= '0' && a <= '9')
        return 2;
    else {
        return 0;
    }
}
