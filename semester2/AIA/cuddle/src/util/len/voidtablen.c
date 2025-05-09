/*
** EPITECH PROJECT, 2025
** voidtablen.c
** File description:
** void ** len
*/

#include "dataframe.h"

int voidtablen(void **tab)
{
    int len = 0;

    for (; tab[len] != NULL; len++);
    return len;
}
