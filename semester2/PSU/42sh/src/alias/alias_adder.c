/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_adder
*/

#include "alias.h"

#include <string.h>

/**
** @brief Add a new aliases to the context aliases.
**    Clone the key and replacement.
** @param context The context where to add the new alias
** @param key The key of the new alias
** @param replacement The replacement of the new alias
** @return The result of the function (See alias#alias_add_result_t)
**/

alias_add_result_t alias_add(shell_context_t *context,
    const char *key, const char *replacement)
{
    char *cloned_key = NULL;
    char *cloned_replacement = NULL;

    if (key == NULL || replacement == NULL) {
        return ALIAS_ADD_FAILED;
    }
    cloned_key = strdup(key);
    cloned_replacement = strdup(replacement);
    if (cloned_key == NULL || cloned_replacement == NULL) {
        free(cloned_key);
        free(cloned_replacement);
        return ALIAS_ADD_FAILED;
    }
    return alias_add_raw(context, cloned_key, cloned_replacement);
}
