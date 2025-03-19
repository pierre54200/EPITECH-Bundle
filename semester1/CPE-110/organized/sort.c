/*
** EPITECH PROJECT, 2024
** sort.c
** File description:
** sort
*/

#include "include/proto.h"
#include "include/shell.h"

int sort(void *data, char **args)
{
    int sorting = 0;
    int reverse = 1;
    data_t **sorted = data;

    if (my_tablen(args) == 0)
        return 84;
    for (int i = 0; args[i] != 0; i++) {
    if (is_a_sort(args[i]) == -1 && my_strcmp(args[i], "-r") != 0)
        return 84;
    }
    if (my_tablen(args) == 1)
        sorting = is_a_sort(args[0]);
    if (my_tablen(args) == 2) {
        sorting = is_a_sort(args[0]);
        reverse = my_strcmp(args[1], "-r");
        if (reverse != 0)
            return 84;
    }
    sort_diff(sorted, sorting, reverse);
    return 0;
}
