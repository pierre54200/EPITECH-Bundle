/*
** EPITECH PROJECT, 2025
** find_in_file.c
** File description:
** find_str_in_file
*/
#include "proto.h"

char *find_in_tab(char **tab, char *str, int pos)
{
    if (tab == NULL)
        return NULL;
    for (int i = 0; tab[i] != 0; i++) {
        if (find_in_string(tab[i], str) != -1
        && ((tab[i][pos] == str[0]) || pos < 0))
            return tab[i];
        }
    return NULL;
}

int find_in_tab_line(char **tab, char *str, int pos)
{
    if (tab == NULL)
        return -1;
    for (int i = 0; tab[i] != 0; i++) {
        if (find_in_string(tab[i], str) != -1
        && ((tab[i][pos] == str[0]) || pos < 0))
            return i;
        }
    return -1;
}
