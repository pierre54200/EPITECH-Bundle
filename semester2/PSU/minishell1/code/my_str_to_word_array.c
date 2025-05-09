/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** task04
*/
#include "../include/proto.h"

int my_in(char want, char *source)
{
    for (int i = 0; source[i] != '\0'; i++)
        if (source[i] == want)
            return 1;
    return 0;
}

int how_many_in(char *source, char *want)
{
    int count = 0;

    for (int i = 0; source[i] != '\0'; i++)
        if (my_in(source[i], want))
            count++;
    return count;
}

char **my_str_to_word_array(char *str)
{
    char *rest = NULL;
    char *token = strtok_r(str, " \n\t", &rest);
    char **stock = malloc(sizeof(char *) * (how_many_in(str, " \t") + 50));
    int i = 1;

    stock[i - 1] = my_strdup(token);
    token = strtok_r(rest, " \n\t", &rest);
    while (token != NULL) {
        stock[i] = my_strdup(token);
        token = strtok_r(rest, " \n\t", &rest);
        i++;
    }
    stock[i] = NULL;
    return stock;
}
