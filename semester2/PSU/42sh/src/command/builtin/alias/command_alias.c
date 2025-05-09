/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** command alias
*/

#include "minishell.h"
#include "alias.h"
#include "shell_command.h"

#include <stdio.h>
#include <string.h>

static int show_alias(shell_context_t *context, char *alias)
{
    alias_t *found = alias_string_find(context, alias);

    if (found == NULL) {
        fprintf(stderr, "alias: %s: not found.\n", alias);
        return 1;
    }
    alias_single_dumper(found);
    return 0;
}

static int override_alias(shell_context_t *context, char *alias)
{
    char *alias_key = alias;
    char *alias_replacement = strstr(alias, "=") + 1;
    alias_add_result_t result = 0;

    (*strstr(alias, "=")) = 0;
    result = alias_add(context, alias_key, alias_replacement);
    if (result == ALIAS_ADD_FAILED) {
        fprintf(stderr, "alias: cannot add: %s.\n", alias_key);
        return 1;
    }
    return 0;
}

static int handle_alias(shell_context_t *context, char *alias)
{
    if (strstr(alias, "=") == NULL) {
        return show_alias(context, alias);
    }
    return override_alias(context, alias);
}

int builtin_command_alias(int argc, char **argv, shell_context_t *context)
{
    int exitcode = 0;

    if (argc == 1) {
        alias_dump(context->aliases);
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        exitcode |= handle_alias(context, argv[i]);
    }
    return exitcode;
}
