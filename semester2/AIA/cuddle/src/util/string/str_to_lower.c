/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** str_to_lower
*/

#include "dataframe.h"

#include <ctype.h>

char *str_to_lower(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
    return str;
}
