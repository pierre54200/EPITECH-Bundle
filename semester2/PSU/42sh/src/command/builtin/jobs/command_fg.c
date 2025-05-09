/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Jobs command: fg
*/
#include "minishell.h"
#include "env.h"
#include "shell_command.h"
#include "command_jobs.h"

#include <stdio.h>

#include <sys/wait.h>
#include <signal.h>


static int handle_signal(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        if (WCOREDUMP(status))
            fprintf(stderr, "Segmentation fault (core dumped)\n");
        else
            fprintf(stderr, "Segmentation fault\n");
        return 139;
    }
    return 139;
}

static int my_fg(shell_context_t *context)
{
    int status = 0;
    job_t *job = context->jobs;

    switch (waitpid(job->pid, &status, 0)) {
        case -1:
            return -1;
        default:
            pop_job(&context->jobs, job);
            return WIFSIGNALED(status) ? handle_signal(status) :
                WEXITSTATUS(status);
    }
    return 0;
}

int builtin_command_fg(int argc, char **argv, shell_context_t *context)
{
    (void) argv;
    if (argc > 1) {
        fprintf(stderr, "mysh: fg: Too many arguments.\n");
        return 1;
    }
    if (!context->jobs) {
        fprintf(stderr, "bash: fg: current: no such job\n");
        return 1;
    }
    return my_fg(context);
}
