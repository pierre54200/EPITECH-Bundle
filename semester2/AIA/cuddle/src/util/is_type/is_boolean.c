/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_float
*/

#include "dataframe.h"

bool is_boolean(char *string)
{
    char *boolean_string = str_to_lower(MY_STRDUPA(string));

    return strcmp(boolean_string, "true") == 0 ||
            strcmp(boolean_string, "false") == 0;
}
