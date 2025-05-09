/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt_username_formatter
*/

#include "minishell.h"
#include "prompt.h"
#include <libgen.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/limits.h>

char *prompt_path_formatter(shell_context_t *context)
{
    char *buffer = malloc(PATH_MAX + 1);
    char *path = NULL;
    char *folder = NULL;

    if (buffer == NULL)
        return strdup("?");
    getcwd(buffer, PATH_MAX);
    folder = basename(buffer);
    if (!context->whole_path)
        asprintf(&path, "%s🗀 %s%s", context->path_color, folder, AC_NORMAL);
    else
        asprintf(&path, "%s🗀 %s%s", context->path_color, buffer, AC_NORMAL);
    if (path == NULL)
        return buffer;
    free(buffer);
    return path;
}
