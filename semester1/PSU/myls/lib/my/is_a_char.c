/*
** EPITECH PROJECT, 2024
** is_a_char
** File description:
** .c
*/
#include "my.h"

int is_a_char(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 0;
    else {
        return 1;
    }
}
