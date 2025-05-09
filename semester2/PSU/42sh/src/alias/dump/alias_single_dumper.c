/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_adder
*/

#include "alias.h"

#include <stdio.h>

/**
** @brief Use to dump a single given aliases
** @param alias The target alias
**/
void alias_single_dumper(alias_t *alias)
{
    printf("alias %s='%s'\n", alias->key, alias->replacement);
}
