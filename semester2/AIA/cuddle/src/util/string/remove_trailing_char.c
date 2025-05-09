/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** remove_trailing_char
*/

#include "dataframe.h"

void remove_trailing_char(char *str, char c)
{
    for (int i = strlen(str) - 1; i >= 0 && str[i] == c; i--) {
        str[i] = '\0';
    }
}
