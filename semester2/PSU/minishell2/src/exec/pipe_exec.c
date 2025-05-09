/*
** EPITECH PROJECT, 2025
** pipe_exec.c
** File description:
** pipie
*/

#include "proto.h"

static char ***split_pipe(shell_t *shell, list_node_t *list)
{
    char ***command = malloc(sizeof(char **) * (list->cmd->pipe + 2));
    char *stock = NULL;
    char *cmd = strtok_r(list->cmd->command_line, "|", &stock);
    int i = 0;

    while (cmd != NULL) {
        command[i] = split_cmd(cmd, " \t");
        i++;
        cmd = strtok_r(stock, "|", &stock);
    }
    command[i] = NULL;
    if (i != list->cmd->pipe + 1) {
        shell->test = 1;
        my_puts("Invalid null command.\n");
    }
    return command;
}

static void wait_pid(int *pid, list_node_t *list, shell_t *shell)
{
    int waitstatus;

    for (int i = 0; i != list->cmd->pipe; i++) {
        waitpid(pid[i], &waitstatus, 0);
        error_exe(waitstatus, shell);
    }
}

static void pipe_child(shell_t *shell, char ***cmd, int fd, int des[])
{
    dup2(fd, STDIN_FILENO);
    if (*(cmd + 1) != NULL)
        dup2(des[1], STDOUT_FILENO);
    close(des[0]);
    if (build_exe(*cmd, shell) != 1)
        execute_in_child(*cmd, shell);
    exit(0);
}

void pipe_exec(list_node_t *list, shell_t *shell)
{
    char ***cmd = split_pipe(shell, list);
    int des[2];
    pid_t *pid = malloc(sizeof(pid_t) * (list->cmd->pipe + 1));
    int fd = 0;

    for (int i = 0; *cmd != NULL; i++) {
        pipe(des);
        pid[i] = fork();
        if (pid[i] == 0)
            pipe_child(shell, cmd, fd, des);
        if (pid[i] > 0) {
            close(des[1]);
            fd = des[0];
            cmd += 1;
        }
    }
    close(des[0]);
    wait_pid(pid, list, shell);
    free(pid);
    exit(0);
}
