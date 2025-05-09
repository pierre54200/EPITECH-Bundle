/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** task04
*/
#include "proto.h"

char **my_str_to_word_array(char *str, char *sep)
{
    char *rest = NULL;
    char *token = strtok_r(str, sep, &rest);
    char **stock = malloc(sizeof(char *) * (counter(str, sep) + 50));
    int i = 1;

    stock[i - 1] = my_strdup(token);
    token = strtok_r(rest, sep, &rest);
    while (token != NULL) {
        stock[i] = my_strdup(token);
        token = strtok_r(rest, sep, &rest);
        i++;
    }
    stock[i] = NULL;
    return stock;
}
