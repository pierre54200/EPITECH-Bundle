/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** shell_command
*/

#ifndef SHELL_COMMAND_H
    #define SHELL_COMMAND_H

    #include "minishell.h"
    #include "my_common.h"

/****************************/
/* BUILT-IN COMMAND HANDLER */
/****************************/

typedef struct {
    char *command;
    int (*command_handler)(int argc, char **argv, shell_context_t *context);
} registered_command_t;

extern const registered_command_t registered_commands[];
extern const int registered_command_count;

/************/
/* BUILT-IN */
/************/

int builtin_command_fg(int argc, char **argv, shell_context_t *context);
int builtin_command_bg(int argc, char **argv, shell_context_t *context);
int builtin_command_jobs(int argc, char **argv, shell_context_t *context);
int builtin_command_exit(int argc, char **argv, shell_context_t *context);
int builtin_command_env(int argc, char **argv, shell_context_t *context);
int builtin_command_setenv(int argc, char **argv, shell_context_t *context);
int builtin_command_unsetenv(int argc, char **argv, shell_context_t *context);
int builtin_command_cd(int argc, char **argv, shell_context_t *context);
int builtin_command_alias(int argc, char **argv, shell_context_t *context);
int builtin_command_unalias(int argc, char **argv, shell_context_t *context);
int builtin_prompt_color(int argc, char **argv, shell_context_t *context);
int builtin_path(int argc, char **, shell_context_t *context);

registered_command_t find_builtin_command(const char *name);

exitcode_t execute_command(shell_context_t *context, char **args);

int my_execve(const char *path, char **argv, shell_context_t *context);
int is_executable(const char *path);

#endif /* !SHELL_COMMAND_H */
