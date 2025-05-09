/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt
*/

#include "prompt.h"
#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *prompt_ask_user(shell_context_t *context)
{
    char *user_input = NULL;

    if (isatty(STDIN_FILENO)) {
        prompt_show_formatted(context, context->prompt_format);
    }
    user_input = prompt_get_input(true, false);
    if (user_input == NULL) {
        shell_stop(context, context->process_exitcode, NULL);
    }
    return user_input;
}
