/*
** EPITECH PROJECT, 2025
** cmd.c
** File description:
** cmd
*/

#include "proto.h"

char **split_cmd(char *str, char *sep)
{
    int size = counter(str, sep);
    char *stock = NULL;
    char *cmd = strtok_r(str, sep, &stock);
    char **cmd_list = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    for (; cmd != NULL; i++) {
        cmd_list[i] = my_strdup(cmd);
        cmd = strtok_r(stock, sep, &stock);
    }
    cmd_list[i] = NULL;
    if (cmd_list[0] == NULL) {
        free(cmd_list);
        return NULL;
    }
    return cmd_list;
}

static cmd_t *split(char *str)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));

    init_stdout(cmd, &str);
    init_stdin(cmd, &str);
    cmd->command_line = my_strdup(str);
    cmd->pipe = counter(str, "|") - 1;
    cmd->command = split_cmd(str, " \t");
    if (cmd->command == NULL)
        return NULL;
    return cmd;
}

void get_cmd(char *line, shell_t *shell)
{
    char *stock = NULL;
    char *cmd = strtok_r(line, ";", &stock);
    cmd_t *command;

    shell->cmd = NULL;
    while (cmd != NULL) {
        command = split(cmd);
        if (command != NULL)
            shell->cmd = push_back(shell->cmd, command);
        cmd = strtok_r(stock, ";", &stock);
    }
}
