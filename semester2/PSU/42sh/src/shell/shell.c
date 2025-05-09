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
#include "alias.h"

#include <stdlib.h>

int shell(shell_context_t *context)
{
    context->running = true;
    alias_reset_usage_state(context->aliases, true);
    shell_rc_loader(context);
    while (context->running && context->is_wait) {
        alias_reset_usage_state(context->aliases, true);
        user_input_handler(context);
    }
    return context->process_exitcode;
}
