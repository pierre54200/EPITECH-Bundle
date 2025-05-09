/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_execution
*/

#include "minishell.h"
#include "string_utils.h"
#include "shell_command.h"

#include <stdio.h>

static int count_args(char **args)
{
    if (*args == 0)
        return 0;
    return count_args(args + 1) + 1;
}

static exitcode_t path_command(char **args, shell_context_t *context)
{
    int exitcode = 0;

    exitcode = my_execve(args[0], args, context);
    if (exitcode < 0) {
        printf("%s: Command not found.\n", args[0]);
        exitcode = 1;
    }
    return exitcode;
}

exitcode_t execute_command(shell_context_t *context, char **args)
{
    registered_command_t found_command = { 0 };
    exitcode_t exit_code = 0;

    if (args == NULL) {
        return -1;
    }
    update_jobs(context);
    found_command = find_builtin_command(args[0]);
    if (found_command.command != 0) {
        exit_code = found_command.command_handler(
            count_args(args), args, context);
    } else {
        exit_code = path_command(args, context);
    }
    return exit_code;
}
