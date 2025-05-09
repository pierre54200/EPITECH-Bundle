/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** command unalias
*/

#include "minishell.h"
#include "alias.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdio.h>

static int process_unalias(shell_context_t *context, char *alias)
{
    alias_remove_result_t result = alias_remove(context, alias);

    if (result == ALIAS_REMOVE_NOTHING) {
        fprintf(stderr, "unalias: %s: not found.\n", alias);
        return 1;
    }
    return 0;
}

int builtin_command_unalias(int argc, char **argv, shell_context_t *context)
{
    int exitcode = 0;

    if (argc <= 1) {
        fprintf(stderr, "unalias: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        exitcode |= process_unalias(context, argv[i]);
    }
    return exitcode;
}
