/*
** EPITECH PROJECT, 2025
** tablen.c
** File description:
** len of char **
*/

#include "dataframe.h"

int tablen(const char **tab)
{
    int len = 0;

    for (; tab[len] != NULL; len++);
    return len;
}
