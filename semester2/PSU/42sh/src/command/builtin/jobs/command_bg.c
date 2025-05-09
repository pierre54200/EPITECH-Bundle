/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Jobs command: bg
*/
#include "minishell.h"
#include "env.h"
#include "shell_command.h"
#include "command_jobs.h"

#include <stdio.h>
#include <signal.h>

static int my_bg(shell_context_t *context)
{
    return kill(context->jobs->pid, SIGCONT);
}

int builtin_command_bg(int argc, char **argv, shell_context_t *context)
{
    (void) argv;
    if (argc > 1) {
        fprintf(stderr, "mysh: bg: Too many arguments.\n");
        return 1;
    }
    if (!context->jobs) {
        fprintf(stderr, "bash: bg: current: no such job\n");
        return 1;
    }
    return my_bg(context);
}
