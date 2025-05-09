/*
** EPITECH PROJECT, 2025
** cleanstr.c
** File description:
** cleanstr
*/

#include "proto.h"

void clean_str(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
}
