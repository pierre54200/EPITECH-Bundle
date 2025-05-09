/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_unique_destroy
*/

#include "alias.h"

/**
** @brief Use to reset all alias to a given state
** @param aliases The target aliases
**/
void alias_reset_usage_state(aliases_t *aliases, bool state)
{
    if (aliases == NULL) {
        return;
    }
    aliases->alias.usable = state;
    alias_reset_usage_state(aliases->next, state);
}
