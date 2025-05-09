/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_setenv
*/

#include "minishell.h"
#include "env.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int validate_varibale_name(char *name)
{
    if (!((name[0] >= 'A' && name[0] <= 'Z') ||
            (name[0] >= 'a' && name[0] <= 'z'))) {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 1; name[i]; i++) {
        if ((name[i] >= 'A' && name[i] <= 'Z') ||
                (name[i] >= 'a' && name[i] <= 'z') ||
                (name[i] >= '0' && name[i] <= '9')) {
            continue;
        }
        fprintf(stderr,
            "setenv: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int builtin_command_setenv(int argc, char **argv, shell_context_t *context)
{
    if (argc > 3) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        return 1;
    }
    if (argc == 1) {
        return builtin_command_env(argc, argv, context);
    }
    if (validate_varibale_name(argv[1]) != 0)
        return 1;
    env_set(context, argv[1], argv[2] == NULL ? "" : argv[2]);
    return 0;
}
