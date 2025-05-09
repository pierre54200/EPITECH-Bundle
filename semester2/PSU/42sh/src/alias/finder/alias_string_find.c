/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_string_find
*/

#include "alias.h"

#include <string.h>

/**
** @brief Find an alias in the aliases list using a string key
** @param context The context of aliases
** @param key The given key
** @return Return the found aliases or NULL
**/
alias_t *alias_string_find(shell_context_t *context, char *key)
{
    aliases_t *current = context->aliases;

    while (current != NULL) {
        if (strcmp(key, current->alias.key) == 0 &&
                alias_is_valid_char(key[strlen(current->alias.key)])) {
            return &current->alias;
        }
        current = current->next;
    }
    return NULL;
}
