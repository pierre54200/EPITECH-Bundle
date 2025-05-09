/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_boolean
*/

#include "dataframe.h"

bool get_boolean(char *string)
{
    char *boolean_string = str_to_lower(MY_STRDUPA(string));

    return strcmp(boolean_string, "true") == 0;
}
