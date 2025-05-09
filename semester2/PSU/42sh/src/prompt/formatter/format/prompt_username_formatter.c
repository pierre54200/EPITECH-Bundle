/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt_username_formatter
*/

#include "prompt.h"
#include "string_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "env.h"
#include <stdio.h>
#include <string.h>

char *prompt_username_formatter(shell_context_t *context)
{
    char *logname = NULL;
    char *prompt = NULL;

    if (context == NULL)
        return strdup("?");
    logname = find_in_env(context, "LOGNAME");
    if (logname == NULL)
        return strdup("?");
    asprintf(&prompt, "%s%s%s", context->user_color, logname, AC_NORMAL);
    if (prompt == NULL)
        return strdup("?");
    return prompt;
}
