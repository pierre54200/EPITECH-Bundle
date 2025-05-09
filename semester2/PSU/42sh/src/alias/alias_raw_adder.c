/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_adder
*/

#include "alias.h"

#include <stdlib.h>

static alias_add_result_t add_new_alias(shell_context_t *context,
    char *key, char *replacement)
{
    alias_remove_result_t remove_result = 0;
    aliases_t *new = calloc(sizeof(aliases_t), 1);

    if (new == NULL) {
        return ALIAS_ADD_FAILED;
    }
    remove_result = alias_remove(context, key);
    new->next = context->aliases;
    context->aliases = new;
    new->alias.key = key;
    new->alias.replacement = replacement;
    new->alias.usable = true;
    return remove_result == ALIAS_REMOVE_SUCCESS
        ? ALIAS_ADD_OVERRIDE : ALIAS_ADD_NEW;
}

/**
** @brief Add a new aliases to the context aliases.
** @param context The context where to add the new aliases
** @param key The key of the new alias
** @param replacement The replacement of the new alias
** @return The result of the function (See alias#alias_add_result_t)
**/
alias_add_result_t alias_add_raw(shell_context_t *context,
    char *key, char *replacement)
{
    if (key == NULL || replacement == NULL) {
        return ALIAS_ADD_FAILED;
    }
    return add_new_alias(context, key, replacement);
}
