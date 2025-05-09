/*
** EPITECH PROJECT, 2025
** count.c
** File description:
** count
*/

#include "proto.h"

int is_in(char want, char *source)
{
    for (int i = 0; source[i] != 0; i++) {
        if (source[i] == want)
            return 1;
    }
    return 0;
}

int counter(char *source, char *want)
{
    int count = 1;

    for (int i = 0; source[i] != 0; i++)
        if (is_in(source[i], want))
            count++;
    return count;
}
