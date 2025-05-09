/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_destroyer
*/

#include "alias.h"

#include <string.h>
#include <stdlib.h>

/**
** @brief Use to free all given aliases.
** @param aliases The target aliases
**/
void alias_destroy(aliases_t *aliases)
{
    if (aliases == NULL) {
        return;
    }
    return alias_destroy(alias_destroy_unique(aliases));
}
