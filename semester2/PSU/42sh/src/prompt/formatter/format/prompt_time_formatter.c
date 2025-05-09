/*
** EPITECH PROJECT, 2025
** prompt_time_formatter.c
** File description:
** format time
*/

#include "minishell.h"
#include "prompt.h"
#include <time.h>
#include <stdio.h>


char *prompt_time_formatter(shell_context_t *context)
{
    char *buffer = malloc(sizeof(char) * (TIME));
    char *timer = NULL;
    time_t t = time(0);

    if (buffer == NULL)
        return NULL;
    if (context->timer != 0)
        context->time = t - context->timer;
    context->timer = t;
    strftime(buffer, sizeof buffer, "%H:%M", localtime(&t));
    asprintf(&timer, "%s%s%s", context->time_color, buffer, AC_NORMAL);
    if (timer == NULL)
        return buffer;
    free(buffer);
    return timer;
}
