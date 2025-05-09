/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_env
*/

#include "minishell.h"
#include "env.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdio.h>
#include "shell_command.h"

static void print_env(env_t *env_variable)
{
    if (env_variable == NULL)
        return;
    print_env(env_variable->next);
    printf("%s=%s\n", env_variable->key, env_variable->value);
}

int builtin_command_env(
    int argc, char **,
    shell_context_t *context)
{
    if (argc != 1)
        return 1;
    print_env(context->env);
    return 0;
}
