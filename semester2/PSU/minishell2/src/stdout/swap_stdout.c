/*
** EPITECH PROJECT, 2025
** swap_stdout.c
** File description:
** stdout
*/

#include "proto.h"

int swap_stdout(list_node_t *list, int *des, int *fd)
{
    if (list->cmd->stdout > 2 || list->cmd->stdout_str == NULL)
        return 0;
    *des = dup(STDOUT_FILENO);
    if (list->cmd->stdout == 1 || list->cmd->stdout == 2)
        *fd = open(list->cmd->stdout_str, O_CREAT | O_APPEND | O_RDWR, 0666);
    if (list->cmd->stdout == 0)
        *fd = *des;
    dup2(*fd, STDOUT_FILENO);
    return 1;
}
