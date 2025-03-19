/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** strlen
*/

#include "../include/hashtable.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != 0) {
        len = len + 1;
    }
    return (len);
}
