/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Manage jobs linked list
*/
#include "minishell.h"
#include "env.h"
#include "shell_command.h"
#include "command_jobs.h"

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

static int sub(shell_context_t *context, int *status, int *i, job_t **next)
{
    for (job_t *temp = context->jobs; temp;) {
        (*i)++;
        *next = temp->next;
        switch (waitpid(temp->pid, status, WNOHANG)) {
        case 0:
            temp = *next;
            continue;
        case -1:
            return -1;
        default:
            printf("[%d]+ Done %s\n", *i, temp->job);
            pop_job(&context->jobs, temp);
            temp = *next;
            break;
        }
    }
    return 0;
}

int update_jobs(shell_context_t *context)
{
    int status = 0;
    int i = 0;
    job_t *next = (job_t *) 0;

    if (!context || !context->jobs) {
        return -1;
    }
    return sub(context, &status, &i, &next);
}
