/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_valid_column_name
*/

#include "dataframe.h"

bool is_valid_column_name(char *name)
{
    if (name[0] == '\0' || strstr(name, "\n") != NULL)
        return false;
    return true;
}
