/*
** EPITECH PROJECT, 2024
** is_a_char
** File description:
** .c
*/
#include "my.h"

int is_a_char(char a)
{
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        return 0;
    else {
        return 1;
    }
}
