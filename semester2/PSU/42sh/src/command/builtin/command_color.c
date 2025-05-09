/*
** EPITECH PROJECT, 2025
** command_color.c
** File description:
** change prompt color
*/

#include "minishell.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdio.h>
#include "prompt.h"
#include "string.h"

static bool is_cmd(char *cmd)
{
    return strcmp(cmd, "time") == 0 || strcmp(cmd, "timer") == 0
    || strcmp(cmd, "git") == 0 || strcmp(cmd, "path") == 0
    || strcmp(cmd, "user") == 0;
}

static bool is_color(char *color)
{
    return strcmp(color, "white") == 0 || strcmp(color, "blue") == 0
    || strcmp(color, "yellow") == 0 || strcmp(color, "green") == 0
    || strcmp(color, "red") == 0;
}

static int help_color(int exit)
{
    fprintf(stdout, "color : change prompt color\n");
    fprintf(stdout, "use : color [prompt] [color]\n");
    fprintf(stdout, "[prompt] : time | timer | user | path | git\n");
    fprintf(stdout, "[color] : white | yellow | blue | green | red\n");
    return exit;
}

static char *select_color(char *color, char *str)
{
    free(str);
    if (strcmp(color, "white") == 0)
        return strdup(AC_NORMAL);
    if (strcmp(color, "yellow") == 0)
        return strdup(AC_YELLOW);
    if (strcmp(color, "blue") == 0)
        return strdup(AC_BLUE);
    if (strcmp(color, "green") == 0)
        return strdup(AC_GREEN);
    if (strcmp(color, "red") == 0)
        return strdup(AC_RED);
    return NULL;
}

int builtin_prompt_color(int argc, char **argv, shell_context_t *context)
{
    if (argc == 1)
        return help_color(0);
    if (argc != 3 || !is_cmd(argv[1]) || !is_color(argv[2]))
        return help_color(1);
    if (strcmp(argv[1], "time") == 0)
        context->time_color = select_color(argv[2], context->time_color);
    if (strcmp(argv[1], "timer") == 0)
        context->timer_color = select_color(argv[2], context->timer_color);
    if (strcmp(argv[1], "user") == 0)
        context->user_color = select_color(argv[2], context->user_color);
    if (strcmp(argv[1], "git") == 0)
        context->git_color = select_color(argv[2], context->git_color);
    if (strcmp(argv[1], "path") == 0)
        context->path_color = select_color(argv[2], context->path_color);
    return 0;
}
