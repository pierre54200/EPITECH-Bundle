/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** my_remove_trailing_char
*/

#include "string_utils.h"

#include <string.h>

char *remove_trailing_char(char *buffer, char c)
{
    if (buffer == NULL || (*buffer) == '\0') {
        return buffer;
    }
    for (size_t i = strlen(buffer) - 1; i != -1UL && buffer[i] == c; i--) {
        buffer[i] = '\0';
    }
    return buffer;
}
