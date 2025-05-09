/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_unsigned_int
*/

#include "dataframe.h"

bool is_unsigned_int(char *string)
{
    return is_signed_int(string) && get_signed_int(string) >= 0;
}
