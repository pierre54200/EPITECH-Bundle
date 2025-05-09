/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_adder
*/

#include "alias.h"

#include <stdio.h>

/**
** @brief Use to dump all given aliases
** @param aliases The target aliases
**/
void alias_dump(aliases_t *aliases)
{
    if (aliases == NULL) {
        return;
    }
    alias_single_dumper(&aliases->alias);
    alias_dump(aliases->next);
}
