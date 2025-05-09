/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt_username_formatter
*/

#include "prompt.h"
#include "string_utils.h"
#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *prompt_exitcode_formatter(shell_context_t *context)
{
    unsigned char code = 0;
    char *str_code = NULL;

    if (context == NULL)
        return strdup("?");
    code = context->process_exitcode;
    if (code == 0)
        asprintf(&str_code, "%s%d%s", AC_GREEN, code, AC_NORMAL);
    if (code > 0)
        asprintf(&str_code, "%s%d%s", AC_RED, code, AC_NORMAL);
    return str_code;
}
