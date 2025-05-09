/*
** EPITECH PROJECT, 2025
** mysh.c
** File description:
** mysh
*/

#include "proto.h"

char **home(char **stock, shell_t *shell)
{
    for (int i = 0; stock[i] != 0; i++) {
        if (stock[i][0] == '~' && my_strlen(stock[i]) == 1)
            stock[i] = my_strdup(shell->home);
    }
    return stock;
}

static int myshbis(shell_t *shell, list_node_t *temp)
{
    int des_fd_in;
    int des_fd_out;
    int fd_in;
    int fd_out;

    if (!swap_stdin(temp, &des_fd_in, &fd_in))
        return 0;
    swap_stdout(temp, &des_fd_out, &fd_out);
    if (temp->cmd->pipe != 0 || build_exe(temp->cmd->command, shell) != 1) {
        exec(temp, shell, temp->cmd->command);
    }
    free(temp->cmd->command_line);
    free_array(temp->cmd->command);
    free(temp->cmd);
    close(fd_in);
    close(fd_out);
    dup2(des_fd_in, STDIN_FILENO);
    dup2(des_fd_out, STDOUT_FILENO);
    return 0;
}

int mysh(char *line, shell_t *shell)
{
    list_node_t *temp;

    clean_str(line);
    get_cmd(line, shell);
    free(line);
    if (shell->cmd == NULL)
        return 0;
    temp = shell->cmd->first;
    while (temp != NULL) {
        myshbis(shell, temp);
        temp = temp->next;
    }
    free_cmd(shell);
    return 0;
}
