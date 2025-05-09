/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_numerical
*/

#include "dataframe.h"

bool is_numerical(char *string)
{
    return is_float(string) ||
        is_unsigned_int(string) ||
        is_signed_int(string);
}
