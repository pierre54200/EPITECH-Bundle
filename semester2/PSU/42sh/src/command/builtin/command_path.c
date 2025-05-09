/*
** EPITECH PROJECT, 2025
** command_path.c
** File description:
** change path
*/

#include "minishell.h"
#include "shell_command.h"

#include <unistd.h>
#include <stdio.h>
#include "prompt.h"
#include "string.h"

int builtin_path(int argc, char **, shell_context_t *context)
{
    if (argc != 1)
        return 1;
    if (context->whole_path == 0)
        context->whole_path = 1;
    else
        context->whole_path = 0;
    return 0;
}
