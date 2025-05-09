/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_adder
*/

#include "alias.h"

#include <string.h>
#include <stdlib.h>

static alias_remove_result_t remove_target_alias(
    aliases_t **aliases, const char *key)
{
    aliases_t *current = (*aliases)->next;
    aliases_t *previous = (*aliases);

    if (strcmp(key, (*aliases)->alias.key) == 0) {
        *aliases = alias_destroy_unique(*aliases);
        return ALIAS_REMOVE_SUCCESS;
    }
    while (current != NULL) {
        if (strcmp(key, current->alias.key) == 0) {
            previous->next = alias_destroy_unique(current);
            return ALIAS_REMOVE_SUCCESS;
        }
        previous = current;
        current = current->next;
    }
    return ALIAS_REMOVE_NOTHING;
}

/**
** @brief Remove an alias for the aliases of the given context
** @param context The context where to remove the target alias
** @param key The key of the alias
** @return The result of the function (See alias#alias_remove_result_t)
**/
alias_remove_result_t alias_remove(shell_context_t *context, const char *key)
{
    if (key == NULL || context->aliases == NULL) {
        return ALIAS_REMOVE_NOTHING;
    }
    return remove_target_alias(&context->aliases, key);
}
