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
#include <signal.h>

#include <stdio.h>
#include <string.h>

int add_job(job_t **head, int pid, char *name)
{
    job_t *new = (job_t *) 0;
    char *temp_name = name;

    if (!name || !temp_name) {
        return 1;
    }
    new = malloc(sizeof(job_t));
    if (!new) {
        return 1;
    }
    new->job = temp_name;
    new->pid = pid;
    if (*head) {
        (*head)->prev = new;
    }
    new->next = *head;
    new->prev = (job_t *) 0;
    *head = new;
    printf("[%d] %d\n", count_jobs(*head), pid);
    return 0;
}

int pop_job(job_t **head, job_t *job)
{
    if (!head || !*head || !job) {
        return -1;
    }
    if (job->prev) {
        job->prev->next = job->next;
    } else {
        *head = job->next;
    }
    if (job->next) {
        job->next->prev = job->prev;
    }
    free(job->job);
    free(job);
    return 0;
}

int clear_jobs(job_t *jobs)
{
    if (!jobs) {
        return 0;
    }
    if (jobs->next) {
        clear_jobs(jobs->next);
    }
    if (kill(jobs->pid, SIGKILL) == -1) {
        return -1;
    }
    free(jobs->job);
    free(jobs);
    return 0;
}

int count_jobs(job_t *jobs)
{
    int count = 0;

    for (job_t *temp = jobs; temp; temp = temp->next) {
        count++;
    }
    return count;
}
