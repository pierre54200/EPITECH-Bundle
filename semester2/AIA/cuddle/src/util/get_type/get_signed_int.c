/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_signed_int
*/

#include "dataframe.h"

int get_signed_int(char *string)
{
    return (int)strtoll(string, NULL, 10);
}
