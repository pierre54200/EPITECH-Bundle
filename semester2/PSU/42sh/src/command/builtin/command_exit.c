/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_exit
*/

#include "minishell.h"
#include "string_utils.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdio.h>
#include "shell_command.h"

int builtin_command_exit(int argc, char **argv, shell_context_t *context)
{
    char *error = NULL;
    int exit_code = 0;

    if (argc > 2) {
        fprintf(stderr, "builtin exit: Too much argument.\n");
        return 1;
    }
    if (argc == 2) {
        exit_code = strtol(argv[1], &error, 10);
        if (*error != '\0') {
            fprintf(stderr, "exit: Expression error.\n");
            return 1;
        }
    }
    if (isatty(1) && isatty(2))
        printf("exit\n");
    context->running = false;
    context->process_exitcode = exit_code;
    return exit_code;
}
