/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Header for command_jobs
*/

#ifndef JOB_CONTROL_H
    #define JOB_CONTROL_H

typedef struct job_s {
    int pid;
    char *job;
    struct job_s *next;
    struct job_s *prev;
} job_t;

int add_job(job_t **head, int pid, char *name);
int clear_jobs(job_t *jobs);
int pop_job(job_t **head, job_t *job);
int count_jobs(job_t *jobs);

int update_jobs(shell_context_t *context);

#endif /* JOB_CONTROL_H */
