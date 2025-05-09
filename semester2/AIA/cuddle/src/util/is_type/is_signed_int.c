/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_signed_int
*/

#include "dataframe.h"

bool is_signed_int(char *string)
{
    char *end_ptr = NULL;

    errno = 0;
    strtoll(string, &end_ptr, 10);
    return errno == 0 && (*end_ptr) == '\0';
}
