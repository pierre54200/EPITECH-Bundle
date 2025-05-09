/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_append_executor
*/

#include "ast.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static void execute_process(int target_fd, ast_t *self)
{
    if (dup2(target_fd, STDOUT_FD) == -1) {
        close(target_fd);
        exit(84);
    }
    close(target_fd);
    exit(ast_exec(self->right));
}

exitcode_t ast_append_executor(ast_t *self)
{
    int target_fd = open(NODE_TOKEN(self->left).token_literal.value[0],
        O_WRONLY | O_CREAT | O_APPEND, 0664);
    exitcode_t exitcode = 0;
    int status = 0;
    pid_t pid = 0;

    if (target_fd == -1)
        return 84;
    pid = fork();
    if (pid == -1) {
        exitcode = 84;
    } else if (pid == 0) {
        execute_process(target_fd, self);
    } else {
        waitpid(pid, &status, 0);
        exitcode = WEXITSTATUS(status);
    }
    close(target_fd);
    return exitcode;
}
