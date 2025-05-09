/*
** EPITECH PROJECT, 2025
** dup_part.c
** File description:
** dup
*/

#include "proto.h"

char *dup_part(char *str, int begin, int *len, char *sep)
{
    char *stock = malloc(sizeof(char) * my_strlen(str));
    int size = 0;
    int i = begin;

    if (stock == NULL)
        return NULL;
    if (str[i] == ' ')
        i++;
    for (; !is_in(str[i], sep) && str[i] != 0; i++) {
        stock[size] = str[i];
        size++;
    }
    stock[size] = 0;
    *len = my_strlen(stock);
    return stock;
}

char *del_part(char *str, int begin, int len)
{
    char *stock = malloc(sizeof(char) * my_strlen(str));
    int size = 0;
    int i = 0;

    if (stock == NULL)
        return NULL;
    for (; str[i] != 0; i++) {
        if (i >= begin && i <= begin + len)
            continue;
        stock[size] = str[i];
        size++;
    }
    stock[size] = 0;
    return stock;
}
