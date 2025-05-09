/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_add_to_array
*/

#include "string_utils.h"

#include <string.h>

void free_str_array(char **array)
{
    if (array == NULL) {
        return;
    }
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
