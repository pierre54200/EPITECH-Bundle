/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** myshell
*/

#ifndef MYSHELL_H
    #define MYSHELL_H

    #include <stdbool.h>
    #include <stdint.h>

    #include "my_common.h"

    #include "../jobs/command_jobs.h"

    #define RC_FILE_PATH "./bash/.42shrc"

/***************/
/*    SHELL    */
/***************/

typedef struct shell_context {
    struct env *env;
    char *whole_command;
    bool running;
    char *prompt_format;
    exitcode_t process_exitcode;
    aliases_t *aliases;
    job_t *jobs;
    long int time;
    long int timer;
    char *time_color;
    char *timer_color;
    char *git_color;
    char *path_color;
    char *user_color;
    bool whole_path;
    bool is_wait;
} shell_context_t;

int shell_rc_loader(shell_context_t *context);
int shell(shell_context_t *context);
void shell_stop(shell_context_t *context,
    exitcode_t exitcode, const char *reason);

void user_input_handler(shell_context_t *context);
void handle_input(shell_context_t *context, char *input);

#endif /* !MYSHELL_H */
