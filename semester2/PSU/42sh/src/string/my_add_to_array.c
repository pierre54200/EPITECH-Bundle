/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_add_to_array
*/

#include "string_utils.h"

#include <string.h>
#include <stdio.h>

char **add_to_array(char **array, char *value)
{
    size_t i = 0;

    if (array == NULL) {
        array = calloc(sizeof(char *), 2);
        if (array != NULL) {
            array[0] = strdup(value);
        }
        return array;
    }
    for (i = 1; array[i - 1] != NULL; i++);
    array = realloc(array, sizeof(char *) * (i + 1));
    if (i != 0) {
        array[i - 1] = strdup(value);
    }
    array[i] = NULL;
    return array;
}
