/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_pipe_executor
*/

#include "ast.h"

#include <sys/wait.h>

static void execute_right_process(ast_t *right, pid_t pipefd[2])
{
    close(pipefd[0]);
    if (dup2(pipefd[1], STDOUT_FD) == -1) {
        exit(84);
    }
    close(pipefd[1]);
    exit(ast_exec(right));
}

static exitcode_t execute_left_process(
    pid_t child_pid, pid_t saved_stdin,
    ast_t *left, pid_t pipefd[2])
{
    exitcode_t exitcode = 0;

    close(pipefd[1]);
    if (dup2(pipefd[0], STDIN_FD) == -1)
        return 84;
    close(pipefd[0]);
    exitcode = ast_exec(left);
    if (dup2(saved_stdin, STDIN_FD) == -1)
        return 84;
    close(saved_stdin);
    waitpid(child_pid, NULL, 0);
    return exitcode;
}

exitcode_t ast_pipe_executor(ast_t *self)
{
    pid_t pipefd[2];
    pid_t pid;
    int saved_stdin = dup(STDIN_FD);

    if (pipe(pipefd) == -1)
        return 84;
    pid = fork();
    if (pid < 0) {
        return 84;
    } else if (pid == 0) {
        execute_right_process(self->right, pipefd);
    }
    return execute_left_process(pid, saved_stdin, self->left, pipefd);
}
