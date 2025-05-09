/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_float
*/

#include "dataframe.h"

bool is_float(char *string)
{
    char *end_ptr = NULL;

    if (strstr(string, ".") == NULL)
        return is_signed_int(string);
    errno = 0;
    strtof(string, &end_ptr);
    return errno == 0 && (*end_ptr) == '\0';
}
