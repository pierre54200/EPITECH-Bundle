/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_signed_int
*/

#include "dataframe.h"

uint32_t get_unsigned_int(char *string)
{
    return (uint32_t) strtoull(string, NULL, 10);
}
