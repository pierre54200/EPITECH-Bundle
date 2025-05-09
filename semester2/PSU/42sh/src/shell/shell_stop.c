/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** shell
*/

#include "minishell.h"
#include "shell_command.h"
#include "parser.h"
#include "token.h"

#include <stdlib.h>
#include <stdio.h>

void shell_stop(shell_context_t *context, uint8_t exitcode, const char *reason)
{
    if (reason != NULL) {
        IF_IS_TTY(fprintf(stderr, "%s", reason));
    }
    context->running = false;
    if (exitcode <= 1)
        context->process_exitcode = exitcode;
    if (exitcode > 1)
        context->process_exitcode = 1;
}
