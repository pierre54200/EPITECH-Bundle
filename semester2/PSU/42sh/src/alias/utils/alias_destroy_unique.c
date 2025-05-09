/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_unique_destroy
*/

#include "alias.h"

/**
** @brief Use to destroy a unique alias
** @param alias The target alias
** @return Return the next of the given alias
**/
aliases_t *alias_destroy_unique(aliases_t *alias)
{
    aliases_t *next = NULL;

    if (alias == NULL) {
        return NULL;
    }
    next = alias->next;
    free(alias->alias.key);
    free(alias->alias.replacement);
    free(alias);
    return next;
}
