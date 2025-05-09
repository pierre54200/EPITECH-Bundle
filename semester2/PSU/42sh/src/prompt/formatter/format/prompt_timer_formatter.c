/*
** EPITECH PROJECT, 2025
** prompt_timer_fomatter.c
** File description:
** timer formatter
*/

#include "minishell.h"
#include "prompt.h"
#include <libgen.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/limits.h>

char *prompt_timer_formatter(shell_context_t *context)
{
    char *timer = NULL;

    asprintf(&timer, "%s%lds%s",
        context->timer_color, context->time, AC_NORMAL);
    if (timer == NULL)
        return strdup("");
    return timer;
}
