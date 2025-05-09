/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Jobs command
*/
#include "minishell.h"
#include "env.h"
#include "shell_command.h"
#include "command_jobs.h"

#include <stdio.h>

int builtin_command_jobs(int argc, char **argv, shell_context_t *context)
{
    int d = 0;

    (void) argv;
    (void) context;
    if (argc > 1) {
        fprintf(stderr, "msh: jobs: Too many arguments.\n");
        return 1;
    }
    for (job_t *temp = context->jobs; temp; temp = temp->next) {
        d++;
        printf("[%d] %s\n", d, temp->job);
    }
    return 0;
}
